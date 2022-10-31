#include "employee.h"

Employee::Employee(QObject* parent)
{

}

Employee::~Employee()
{

}

Employee::Employee(QString name, int av)
{
    setEmployeeName(name);
    setAverage(av);
}

void Employee::setEmployeeName(QString name)
{
    m_employeeName = name;
}

void Employee::setAverage(int average)
{
    m_average = average;
}

QString Employee::employeeName() const
{
    return m_employeeName;
}

int Employee::average() const
{
    return m_average;
}


