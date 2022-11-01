#include "mqhelper.h"
#include <sys/errno.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>


MqHelper::MqHelper()
{

}

MqHelper::~MqHelper()
{

}

mqd_t MqHelper::connect(ClientType type)
{
    std::string address;
    if (type == ClientType::viewer) {
        address = MQNAME_VIEWER;
    }
    else address = MQNAME_EDITOR;
    mqd_t res = mq_open(address.c_str(), O_RDWR);
    if (res == -1 ) perror("mq_open error: ");
    return res;
}

mqd_t MqHelper::create(ClientType type)
{
    std::string address;
    if (type == ClientType::viewer) {
        address = MQNAME_VIEWER;
    }
    else address = MQNAME_EDITOR;
    mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MQ;
    attr.mq_msgsize = MAX_MQ_MESS_LEN;
    mqd_t res = mq_open(address.c_str(), O_CREAT | O_RDWR ,  APPROVAL, &attr);
    if (res == -1 ) perror("mq_open error: ");
    return res;
}


int MqHelper::send(mqd_t mqdes, MyMess* mess )
{
    int res = mq_send(mqdes, (char*) mess, 1024, 0);
    if (res == -1 ) perror("mq_send error: ");
    return res;
}

ssize_t MqHelper::receive(mqd_t mqdes, MyMess* mess)
{
    ssize_t res= mq_receive(mqdes, (char*) mess, MAX_MQ_MESS_LEN + 2, NULL);
    if (res == -1 ) perror("mq_receive error: ");
    return res;
}

