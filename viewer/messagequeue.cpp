#include "messagequeue.h"
#include <cstring>
#include <iostream>

MessageQueue::MessageQueue()
{
    m_mqHelper = new MqHelper();
    this->connect();
}

void MessageQueue::connect()
{
    m_mqDes = m_mqHelper->connect(ClientType::viewer);
    MyMess* test = new MyMess();
    test->type = edit;
    std::string name = "Tran Duy Hiep";
    memcpy(test->name, name.c_str(), sizeof(name));
    std::cout << test->name << std::endl;
    std::cout << std::endl;
    test->grade[3] = 5;
    m_mqHelper->send(m_mqDes, test);
}
