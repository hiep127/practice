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
            std::cout << "receiving1     " << m_mqMess.grade[0] << "   " << m_mqMess.type <<  std::endl;
            int _type = m_mqMess.grade[0] ;
            switch(_type) {
            case MqType::dataChanged: {
                std::cout << "receiving2" << std::endl;
                emit sigDataChanged();
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
