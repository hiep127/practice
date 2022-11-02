#ifndef MQHELPER_H
#define MQHELPER_H

#include "CommonDefine.h"
#include <mqueue.h>

class MqHelper
{
public:
    MqHelper();
    ~MqHelper();
    mqd_t connect(ClientType type);
    mqd_t create(ClientType type);
    int send(mqd_t mqdes, MyMess* mess );
    ssize_t receive(mqd_t mqdes, MyMess* mess );
};

#endif // MQHELPER_H
