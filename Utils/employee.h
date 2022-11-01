#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QObject>
#include <QMetaType>

class Employee : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString employeeName READ employeeName WRITE setEmployeeName NOTIFY employeeNameChanged);
    Q_PROPERTY(float average READ average WRITE setAverage NOTIFY averageChanged)
public:
    Employee(QObject *parent = nullptr);
    ~Employee();
    Employee(QString name, int av);
    void setEmployeeName(QString name);
    void setAverage(int average);
    QString employeeName() const;
    float average() const;
signals:
    void employeeNameChanged();
    void averageChanged();
private:
    QString m_employeeName;
    float m_average;
};
Q_DECLARE_METATYPE(Employee*)

#endif // EMPLOYEE_H
