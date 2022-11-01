#ifndef MAINSERVICE_H
#define MAINSERVICE_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>
#include <../Utils/mqhelper.h>
#include <../Utils/IPCDefine.h>
#include <datahelper.h>
#include <../Utils/shmhelper.h>
#include <thread>


class MainService
{
public:
    MainService();
    ~MainService();
    void createMQ();
    void send(ClientType type, MyMess mess);
    void *receiveFromViewer();
    void *receiveFromEditor();
    void runViewerMQ();
    void runEditorMQ();
    void initData();
    void writeData(std::vector<EmployeeGrade> data);
    void initShm();
    void readData();
    void notifyDataChanged();



private:
    mqd_t m_editorMqDes;
    mqd_t m_viewerMqDes;
    mq_attr m_attr;
    unsigned int m_prio;
    MqHelper* m_mqHelper;
    MyMess m_viewerMess;
    MyMess m_editorMess;
    std::thread* m_thread[NUM_OF_THREAD];
    DataHelper* m_dataHelper;
    ShmHelper* m_shmHelper;
    std::vector<EmployeeGrade> m_gradeData;
    int m_shmDes;
    std::vector<EmployeeData> m_eData;
};

#endif // MAINSERVICE_H
