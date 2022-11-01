#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <../Utils/mqhelper.h>
#include <../Utils/IPCDefine.h>
#include <QObject>
#include <thread>
//#include <queue>

class MessageQueue : public QObject
{
    Q_OBJECT
public:
    MessageQueue(QObject* parent = nullptr);
    ~MessageQueue();
    void connect();
    void *receive();
    void runMQThread();
    void searchForId(int id);

signals:
    void sigDataChanged();
    void sigEmployeeData(EmployeeGrade grade);

private:
    mqd_t m_mqDes;
    mq_attr m_attr;
    unsigned int m_prio;
    MqHelper* m_mqHelper;
    MyMess m_mqMess;
    //std::thread m_thread;
    //static
};

#endif // MESSAGEQUEUE_H
