#include "mainservice.h"

MainService::MainService()
{
    m_mqHelper = new MqHelper();
    m_dataHelper = new DataHelper();
    m_shmHelper = new ShmHelper();
    this->createMQ();
    this->runEditorMQ();
    this->runViewerMQ();
    this->initData();
    this->initShm();
    this->writeData(m_gradeData);
    this->readData();
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
}


void MainService::send(char *address, MyMess mess)
{

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
}

void MainService::readData()
{
    m_shmHelper->readData(m_eData, m_shmDes);
    std::cout << "entering" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << m_eData[i].name << std::endl;
    }
}
