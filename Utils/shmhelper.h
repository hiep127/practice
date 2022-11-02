#ifndef SHMHELPER_H
#define SHMHELPER_H

#define EMPLOYEE_NUM 21

#include <sys/shm.h>
#include <sys/mman.h>
#include "CommonDefine.h"
#include <fcntl.h>

class ShmHelper
{
public:
    ShmHelper();
    ~ShmHelper();
    int createShm();
    void writeData(std::vector<EmployeeData> data, EmployeeData* addr);
    //void readData(std::vector<EmployeeData> &rData, EmployeeData* addr);
    EmployeeData* createAddrrForWrite(int des);
    EmployeeData* createAddrrForRead(int des);
    int openShmForRead();
};

#endif // SHMHELPER_H
