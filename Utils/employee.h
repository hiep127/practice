#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QObject>
#include <QMetaType>

class Employee : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString employeeName READ employeeName WRITE setEmployeeName NOTIFY employeeNameChanged);
    Q_PROPERTY(float average READ average WRITE setAverage NOTIFY averageChanged)
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
public:
    Employee(QObject *parent = nullptr);
    ~Employee();
    Employee(QString name, float av, int id = -1);
    void setEmployeeName(QString name);
    void setAverage(float average);
    void setId(int id);
    QString employeeName() const;
    float average() const;
    int id() const;
signals:
    void employeeNameChanged();
    void averageChanged();
    void idChanged();
private:
    QString m_employeeName;
    float m_average;
    int m_id;
};
Q_DECLARE_METATYPE(Employee*)

#endif // EMPLOYEE_H
