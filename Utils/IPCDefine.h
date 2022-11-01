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

#define MQ_TYPE_INDEX 5
#define ID_INDEX 6


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
    int data[7] {1,1,1,1,1,0,0};
    char name[4096];
    int type;
};

struct EmployeeData {
    int id;
    char name[128];
    float average;
};

struct EmployeeGrade {
    int id;
    std::string eName;
    std::vector<int> grade;
};

#endif // IPCDEFINE_H
