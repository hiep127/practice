#include "shmhelper.h"
#include <cstring>
#include <iostream>
#include <ostream>
#include <unistd.h>

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
    EmployeeData* e;
    e = (EmployeeData*) mmap(0, 4096, PROT_READ , MAP_SHARED, des, 0);
    int i = 0;
    EmployeeData temp;
    size_t sizeOfArray = sizeof(e)/sizeof(EmployeeData);
    std::cout << sizeOfArray << std::endl;

//    while ((e + i) != nullptr) {
//        std::cout << i << std::endl;
//        strncpy(temp.name, (e + i)->name, sizeof((e + i)->name));
//        temp.id = (e + i)->id;
//        temp.average = (e+i)->average;
//        rData.push_back(temp);
//        i++;
//    }
}
