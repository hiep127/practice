#include "mainservice.h"

MainService::MainService()
{
    m_mqHelper = new MqHelper();
    m_dataHelper = new DataHelper();
    m_shmHelper = new ShmHelper();
    this->createMQ();
    this->initData();
    this->initShm();
    m_thread[ClientType::viewer]->join();
    m_thread[ClientType::editor]->join();
}

MainService::~MainService()
{
    munmap(m_addresForWrite, 4096);
    shmdt(m_addresForWrite);
    close(m_shmDes);
    shmctl(m_shmDes,IPC_RMID,NULL);
}

void MainService::createMQ()
{
    m_editorMqDes = m_mqHelper->create(ClientType::editor);
    m_viewerMqDes = m_mqHelper->create(ClientType::viewer);
    this->runEditorMQ();
    this->runViewerMQ();
}


void MainService::send(ClientType type, MyMess mess)
{
    int mqDes = (type == ClientType::editor) ? m_editorMqDes : m_viewerMqDes;
    m_mqHelper->send(mqDes, &mess);
}

void* MainService::receiveFromViewer()
{

    MqHelper* viewerHelper = new MqHelper();
    MyMess _viewerMess;
    while (true) {
        ssize_t sz = viewerHelper->receive(m_viewerMqDes, &_viewerMess);
        if (sz > 0) {
            std::cout << "receive from viewer " << std::endl;
            this->processMessage(ClientType::viewer, _viewerMess, viewerHelper, m_viewerMqDes);
        }
    }
}

void *MainService::receiveFromEditor()
{
    MqHelper* editorHelper = new MqHelper();
    MyMess _editorMess;
    while (true) {
        ssize_t sz = editorHelper->receive(m_editorMqDes, &_editorMess);
        if (sz > 0) {
            std::cout << "receive from editor " << std::endl;
            this->processMessage(ClientType::editor, _editorMess, editorHelper, m_editorMqDes);
        }
    }
}

void MainService::runViewerMQ()
{
    m_thread[ClientType::viewer] = new std::thread(&MainService::receiveFromViewer, this);
    //t1.detach();
}

void MainService::runEditorMQ()
{
    std::thread t2 (&MainService::receiveFromEditor, this);
    t2.detach();
}

void MainService::initData()
{
    m_mutex.lock();
    m_gradeData = m_dataHelper->getDataFromFile(FILE_LOCATION);
    m_eData = m_dataHelper->convertToEmployeeList(m_gradeData);
    //m_dataHelper->printData(m_data);
    m_mutex.unlock();
}

void MainService::writeData(std::vector<EmployeeGrade> data)
{
    std::vector<EmployeeData> _data = m_dataHelper->convertToEmployeeList(data);
    m_shmHelper->writeData(_data, m_addresForWrite);
}

void MainService::initShm()
{
    m_shmDes = m_shmHelper->createShm();
    m_addresForWrite = m_shmHelper->createAddrrForWrite(m_shmDes);
    this->notifyDataChanged(m_eData, m_mqHelper, m_viewerMqDes);
    this->notifyDataChanged(m_eData, m_mqHelper, m_editorMqDes);
    //this->readData();
}

void MainService::readData()
{
    std::cout << "readData" << std::endl;
    //m_shmHelper->readData(m_eData, m_shmDes);
    for (auto i : m_eData) {
        std::cout << i.name << std::endl ;
    }
}

void MainService::notifyDataChanged(std::vector<EmployeeData> data, MqHelper *helper, mqd_t mqDes)
{
    std::cout << "data changed" << std::endl;
    m_shmHelper->writeData(data, m_addresForWrite);
    MyMess mess;
    mess.type = MqType::dataChanged;
    mess.data[MQ_TYPE_INDEX] = MqType::dataChanged;
    mess.data[NUM_INDEX] = data.size();
    helper->send(mqDes, &mess);
}

void MainService::queryData(int id, MqHelper* helper, mqd_t mqDes)
{
    EmployeeGrade res = m_dataHelper->queryForId(id, m_gradeData);
    MyMess data;
    data.data[MQ_TYPE_INDEX] = query;
    strncpy(data.name, res.eName.c_str(), sizeof(res.eName));
    for (int i = 0; i < 5; i++) {
        data.data[i] = res.grade[i];
    }
    helper->send(mqDes, &data);
}

void MainService::searchText(std::string text, MqHelper *helper, mqd_t mqDes)
{
    std::cout << "search" << std::endl;
    m_mutex.lock();
    std::vector<EmployeeData> temp = m_dataHelper->searchForText(text, m_eData);
    this->notifyDataChanged(temp, helper, mqDes);
    m_mutex.unlock();
}

void MainService::processMessage(ClientType type, MyMess &mess, MqHelper *helper, mqd_t mqDes)
{
    int _type = mess.data[MQ_TYPE_INDEX];
    switch (_type) {
    case MqType::query: {
        int id = mess.data[ID_INDEX];
        this->queryData(id, helper, mqDes);
        break;
    }
    case MqType::search: {
        std::string text = mess.name;
        this->searchText(text, helper, mqDes);
        break;
    }
    case MqType::getFullList: {
        this->initData();
        m_shmHelper->writeData(m_eData, m_addresForWrite);
        this->notifyDataChanged(m_eData, helper, mqDes);
        break;
    case MqType::edit: {
            this->editData(mess, helper);
            break;
        }
    }
    default:
        break;
    }
}

void MainService::editData(const MyMess &mess, MqHelper *helper)
{
    std::vector<int> temp;
    for (int i = 0; i < MAX_DATA; i++) {
        temp.push_back(mess.data[i]);
    }
    m_dataHelper->editData(m_gradeData, temp, FILE_LOCATION);
    m_eData = m_dataHelper->convertToEmployeeList(m_gradeData);
    this->notifyDataChanged(m_eData, helper, m_editorMqDes);
    this->notifyDataChanged(m_eData, m_mqHelper, m_viewerMqDes);
}
