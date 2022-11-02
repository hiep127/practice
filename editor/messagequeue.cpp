#include "messagequeue.h"
#include <cstring>
#include <iostream>


MessageQueue::MessageQueue(QObject *parent)
{
    m_mqHelper = new MqHelper();
    this->connect();
}

MessageQueue::~MessageQueue()
{

}

void MessageQueue::connect()
{
    std::cout << "conencting" << std::endl;
    m_mqDes = m_mqHelper->connect(ClientType::viewer);
    this->runMQThread();
}

void *MessageQueue::receive()
{
    while (true) {
        ssize_t sz =  m_mqHelper->receive(m_mqDes, &m_mqMess);
        if (sz > 0) {
            std::cout << "receiving1     " << m_mqMess.data[MQ_TYPE_INDEX] <<  std::endl;
            int _type = m_mqMess.data[MQ_TYPE_INDEX] ;
            switch(_type) {
            case MqType::dataChanged: {
                 std::cout << "receiving2     " << std::endl;
                 int num = m_mqMess.data[NUM_INDEX];
                 emit sigDataChanged(num);
                 break;
            }
            case MqType::query: {
                std::cout << "receiving2     " << std::endl;
                EmployeeGrade _grade;
                _grade.id = m_mqMess.data[ID_INDEX];
                _grade.eName = m_mqMess.name;
                _grade.grade.resize(5);
                for (int i = 0; i < 5; i++) {
                    _grade.grade[i] = m_mqMess.data[i];
                }
                emit sigEmployeeData(_grade);
                break;
            }
            default:
                break;
            }
        }
    }
}

void MessageQueue::runMQThread()
{
    std::thread t1 (&MessageQueue::receive, this);
    t1.detach();
}

void MessageQueue::queryForId(int id)
{
    std::cout << "search for id: " << id << std::endl;
    MyMess mess;
    mess.type = MqType::query;
    mess.data[ID_INDEX] = id;
    m_mqHelper->send(m_mqDes, &mess);
}

void MessageQueue::searchText(QString inp)
{
    MyMess mess;
    mess.data[MQ_TYPE_INDEX] = MqType::search;
    strncpy(mess.name, inp.toStdString().c_str(), sizeof(inp.toStdString()));
    m_mqHelper->send(m_mqDes, &mess);

}

void MessageQueue::requestFullList()
{
    MyMess mess;
    mess.data[MQ_TYPE_INDEX] = MqType::getFullList;
    m_mqHelper->send(m_mqDes, &mess);
}

void MessageQueue::editData(const std::vector<int> &data)
{
    MyMess mess;
    for (int i = 0; i < 7; i++) {
        mess.data[i] = data[i];
    }
    m_mqHelper->send(m_mqDes, &mess);

}
