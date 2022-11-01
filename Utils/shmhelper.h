#ifndef SHMHELPER_H
#define SHMHELPER_H

#include <sys/shm.h>
#include <sys/mman.h>
#include "IPCDefine.h"
#include <fcntl.h>

class ShmHelper
{
public:
    ShmHelper();
    ~ShmHelper();
    int createShm();
    void writeData(std::vector<EmployeeData> data, int des);
    void readData(std::vector<EmployeeData> &rData, int des);
};

#endif // SHMHELPER_H
