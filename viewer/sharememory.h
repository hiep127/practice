#ifndef SHAREMEMORY_H
#define SHAREMEMORY_H

#include <QObject>
#include <../Utils/shmhelper.h>


class ShareMemory : public QObject
{
    Q_OBJECT
public:
    ShareMemory();
    ~ShareMemory();
    void openShm();
    std::vector<EmployeeData> readData(int num);

private:
    int m_shmDes;
    ShmHelper* m_helper;

    EmployeeData* m_addrForRead;


};

#endif // SHAREMEMORY_H
