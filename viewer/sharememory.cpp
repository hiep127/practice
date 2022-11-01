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
}

std::vector<EmployeeData> ShareMemory::readData()
{
    std::cout << "readData" << std::endl;
    m_helper->readData(m_eData, m_shmDes);
    std::cout << m_eData[0].name << std::endl;
    return m_eData;
}
