#include "employee.h"

Employee::Employee(QObject* parent)
{

}

Employee::~Employee()
{

}

Employee::Employee(QString name, float av, int id)
{
    setEmployeeName(name);
    setAverage(av);
    setId(id);
}

void Employee::setEmployeeName(QString name)
{
    m_employeeName = name;
}

void Employee::setAverage(float average)
{
    m_average = average;
}

void Employee::setId(int id)
{
    m_id = id;
}

QString Employee::employeeName() const
{
    return m_employeeName;
}

float Employee::average() const
{
    return m_average;
}

int Employee::id() const
{
    return m_id;
}


