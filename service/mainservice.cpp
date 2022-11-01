#include "mainservice.h"

MainService::MainService()
{
    m_mqHelper = new MqHelper();
    m_dataHelper = new DataHelper();
    m_shmHelper = new ShmHelper();
    this->createMQ();
    this->initData();
    m_thread[ClientType::viewer]->join();
}

MainService::~MainService()
{

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
            int _type = _viewerMess.data[MQ_TYPE_INDEX];
            switch (_type) {
            case search: {
                int id = _viewerMess.data[ID_INDEX];
                EmployeeGrade res = m_dataHelper->searchForId(id, m_gradeData);
                MyMess data;
                data.data[MQ_TYPE_INDEX] = search;
                strncpy(data.name, res.eName.c_str(), sizeof(res.eName));
                for (int i = 0; i < 5; i++) {
                    data.data[i] = res.grade[i];
                }
                viewerHelper->send(m_viewerMqDes, &data);
            }
            default:
                break;
            }

        }
    }
}

void *MainService::receiveFromEditor()
{
    MqHelper* viewerHelper = new MqHelper();
    MyMess* _editorMess = new MyMess();
    while (true) {
        ssize_t sz = viewerHelper->receive(m_editorMqDes, _editorMess);
        if (sz > 0) {
            // Do sth later
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
    m_gradeData = m_dataHelper->getDataFromFile(FILE_LOCATION);
    m_eData = m_dataHelper->convertToEmployeeList(m_gradeData);
    this->initShm();
    //m_dataHelper->printData(m_data);
}

void MainService::writeData(std::vector<EmployeeGrade> data)
{
    std::vector<EmployeeData> _data = m_dataHelper->convertToEmployeeList(data);
    m_shmHelper->writeData(_data, m_shmDes);
}

void MainService::initShm()
{
    m_shmDes = m_shmHelper->createShm();

    this->notifyDataChanged();
    //this->readData();
}

void MainService::readData()
{
    std::cout << "readData" << std::endl;
    m_shmHelper->readData(m_eData, m_shmDes);
    for (auto i : m_eData) {
        std::cout << i.name << std::endl ;
    }
}

void MainService::notifyDataChanged()
{
    std::cout << "data changed" << std::endl;
    m_shmHelper->writeData(m_eData, m_shmDes);
    MyMess mess;
    mess.type = dataChanged;
    mess.data[MQ_TYPE_INDEX] = dataChanged;
    strncpy (mess.name, "hello", sizeof("hello"));
    m_mqHelper->send(m_viewerMqDes, &mess);
}
