#ifndef IPCDEFINE_H
#define IPCDEFINE_H

#include <vector>
#include <string>

#define MAX_MQ_MESS_LEN 8192
#define MAX_MQ 9

#define APPROVAL 0666

#define MQNAME_VIEWER "/mq_viewer"
#define MQNAME_EDITOR "/mq_editor"

#define MY_SHM "/my_shm"


enum ClientType {
    viewer = 0,
    editor
};

enum MqType {
    search = 0,
    edit,
    dataChanged
};


struct MyMess {
    int grade[5] {1,1,1,1,1};
    char name[4096];
    int type;
};

struct EmployeeData {
    int id;
    char name[128];
    float average;
};

#endif // IPCDEFINE_H
