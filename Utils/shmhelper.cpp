#include "shmhelper.h"
#include <cstring>
#include <iostream>
#include <ostream>
#include <unistd.h>
//#include <ServiceDefine.h>
ShmHelper::ShmHelper()
{

}

ShmHelper::~ShmHelper()
{

}

int ShmHelper::createShm()
{
    int sh_des = shm_open("/my_shm", O_CREAT | O_RDWR, APPROVAL);
    if (sh_des < 0)
        perror("shm_open: ");
    ftruncate(sh_des, 4096);
    return sh_des;
}

void ShmHelper::writeData(std::vector<EmployeeData> data, int des)
{
    EmployeeData* wData = new EmployeeData[data.size()];
    wData = (EmployeeData*) mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, des, 0);
    for (size_t i = 0; i < data.size(); i++) {
        wData[i].id = data[i].id;
        strncpy(wData[i].name, data[i].name, sizeof(data[i].name));
        //std::cout << wData[i].name  << std::endl;
        wData[i].average = data[i].average;
    }
}

void ShmHelper::readData(std::vector<EmployeeData> &rData, int des)
{
    EmployeeData* data;
    data = (EmployeeData*) mmap(0, 4096, PROT_READ , MAP_SHARED, des, 0);
    EmployeeData temp;
    for (int i = 0; i < EMPLOYEE_NUM; i++) {
        strncpy(temp.name, data[i].name, sizeof(data[i].name));
        temp.id = data[i].id;
        temp.average = data[i].average;
        rData.push_back(temp);
    }
}

int ShmHelper::openShmForRead()
{
    int sh_des = shm_open("/my_shm", O_CREAT | O_RDONLY, APPROVAL);
    if (sh_des < 0)
        perror("shm_open: ");
    return sh_des;
}
