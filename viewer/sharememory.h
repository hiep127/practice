#ifndef SHAREMEMORY_H
#define SHAREMEMORY_H

#include <QObject>
#include </home/avn//practice/Utils/shmhelper.h>


class ShareMemory : public QObject
{
    Q_OBJECT
public:
    ShareMemory();
    ~ShareMemory();
    void openShm();
    std::vector<EmployeeData> readData();

private:
    int m_shmDes;
    ShmHelper* m_helper;
    std::vector<EmployeeData> m_eData;


};

#endif // SHAREMEMORY_H
