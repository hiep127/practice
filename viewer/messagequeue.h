#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include </home/avn/practice/Utils/mqhelper.h>
#include </home/avn//practice/Utils/IPCDefine.h>

class MessageQueue
{
public:
    MessageQueue();
    ~MessageQueue();
    void connect();

private:
    mqd_t m_mqDes;
    mq_attr m_attr;
    unsigned int m_prio;
    MqHelper* m_mqHelper;
    MyMess m_mqMess;
    pthread_t m_thread;
};

#endif // MESSAGEQUEUE_H
