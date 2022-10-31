#ifndef IPCDEFINE_H
#define IPCDEFINE_H

#define MAX_MQ_MESS_LEN 1024
#define MAX_MQ 9

#define APPROVAL 0666

#define MQNAME "/my_mq"

enum MqType {
    client = 0,
    server
};

#endif // IPCDEFINE_H
