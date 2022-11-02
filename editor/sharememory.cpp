#include "sharememory.h"
#include <iostream>

ShareMemory::ShareMemory()
{
    m_helper = new ShmHelper();
    this->openShm();
}

ShareMemory::~ShareMemory()
{

}

void ShareMemory::openShm()
{
    m_shmDes = m_helper->openShmForRead();
    m_addrForRead = m_helper->createAddrrForRead(m_shmDes);
}

std::vector<EmployeeData> ShareMemory::readData(int num)
{
    std::vector<EmployeeData> eData;
    EmployeeData temp;
    std::cout << "readData" << std::endl;
    //m_helper->readData(m_eData, m_shmDes);
    for (int i = 0; i < num; i++) {
        strncpy(temp.name, m_addrForRead[i].name, sizeof(m_addrForRead[i].name));
        temp.id = m_addrForRead[i].id;
        temp.average = m_addrForRead[i].average;
        eData.push_back(temp);
    }
    std::cout << eData[0].name << std::endl;
    return eData;
}
