#include "mqhelper.h"
#include <sys/errno.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string>
#include <sys/stat.h>
#include <fcntl.h>
#include "IPCDefine.h"

MqHelper::MqHelper()
{

}

MqHelper::~MqHelper()
{

}

mqd_t MqHelper::connect()
{
    mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MQ;
    attr.mq_msgsize = MAX_MQ_MESS_LEN;
    mqd_t res = mq_open(MQNAME, O_CREAT | O_RDWR ,  APPROVAL, &attr);
    if (res == -1 ) perror("mq_open error: ");
    return res;
}


int MqHelper::send(mqd_t mqdes, char *text)
{
    int res = mq_send(mqdes, text, sizeof(text), 0);
    if (res == -1 ) perror("mq_send error: ");
    return res;
}

ssize_t MqHelper::receive(mqd_t mqdes, char *text)
{
    ssize_t res= mq_receive(mqdes, text, 1025, 0);
    if (res == -1 ) perror("mq_receive error: ");
    return res;
}

