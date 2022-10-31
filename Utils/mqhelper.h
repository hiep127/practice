#ifndef MQHELPER_H
#define MQHELPER_H

#include <mqueue.h>

class MqHelper
{
public:
    MqHelper();
    ~MqHelper();
    mqd_t connect();
    int send(mqd_t mqdes, char* text);
    ssize_t receive(mqd_t mqdes, char* text);
};

#endif // MQHELPER_H
