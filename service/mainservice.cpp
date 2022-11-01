#include "mainservice.h"

MainService::MainService()
{
    m_mqHelper = new MqHelper();
    m_dataHelper = new DataHelper();
    m_shmHelper = new ShmHelper();
    this->createMQ();
    this->initData();
    pthread_join(m_thread[ClientType::viewer], NULL);
    pthread_join(m_thread[ClientType::editor], NULL);
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

void* MainService::receiveFromViewer(void*)
{

    MqHelper* viewerHelper = new MqHelper();
    mqd_t _viewerMqDes = viewerHelper->connect(ClientType::viewer);;
    MyMess _viewerMess;
    while (true) {
        ssize_t sz = viewerHelper->receive(_viewerMqDes, &_viewerMess);
        if (sz > 0) {
            std::cout << "receive from viewer " << std::endl;
            for (auto i : _viewerMess.grade) {
                std::cout << i << " ";
            }
            std::cout << _viewerMess.name << _viewerMess.type << std::endl;

        }
    }
    pthread_exit(NULL);
}

void *MainService::receiveFromEditor(void *)
{
    MqHelper* viewerHelper = new MqHelper();
    mqd_t _editorMqDes = viewerHelper->connect(ClientType::editor);;
    MyMess* _editorMess = new MyMess();
    while (true) {
        ssize_t sz = viewerHelper->receive(_editorMqDes, _editorMess);
        if (sz > 0) {
            // Do sth later
        }
    }
    pthread_exit(NULL);
}

void MainService::runViewerMQ()
{
    pthread_create(&m_thread[ClientType::viewer], NULL, receiveFromViewer, NULL);
}

void MainService::runEditorMQ()
{
    pthread_create(&m_thread[ClientType::editor], NULL, receiveFromEditor, NULL);
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
    mess.grade[0] = dataChanged;
    strncpy (mess.name, "hello", sizeof("hello"));
    m_mqHelper->send(m_viewerMqDes, &mess);
}
