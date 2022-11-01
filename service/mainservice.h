#ifndef MAINSERVICE_H
#define MAINSERVICE_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>
#include </home/avn/practice/Utils/mqhelper.h>
#include </home/avn//practice/Utils/IPCDefine.h>
#include <datahelper.h>
#include </home/avn//practice/Utils/shmhelper.h>


class MainService
{
public:
    MainService();
    ~MainService();
    void createMQ();
    void send(char* address, MyMess mess);
    static void *receiveFromViewer(void*);
    static void *receiveFromEditor(void*);
    void runViewerMQ();
    void runEditorMQ();
    void initData();
    void writeData(std::vector<EmployeeGrade> data);
    void initShm();
    void readData();



private:
    mqd_t m_editorMqDes;
    mqd_t m_viewerMqDes;
    mq_attr m_attr;
    unsigned int m_prio;
    MqHelper* m_mqHelper;
    MyMess m_viewerMess;
    MyMess m_editorMess;
    pthread_t m_thread[NUM_OF_THREAD];
    DataHelper* m_dataHelper;
    ShmHelper* m_shmHelper;
    std::vector<EmployeeGrade> m_gradeData;
    int m_shmDes;
    std::vector<EmployeeData> m_eData;
};

#endif // MAINSERVICE_H
