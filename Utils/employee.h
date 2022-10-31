#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QObject>
#include <QMetaType>

class Employee : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString employeeName READ name WRITE setemployeeName NOTIFY employeeNameChanged);
    Q_PROPERTY(int average READ average WRITE setAverage NOTIFY averageChanged)
public:
    Employee(QObject *parent = nullptr);
    ~Employee();
    Employee(QString name, int av);
    void setEmployeeName(QString name);
    void setAverage(int average);
    QString employeeName() const;
    int average() const;
signals:
    void employeeNameChanged();
    void averageChanged();
private:
    QString m_employeeName;
    int m_average;
};
Q_DECLARE_METATYPE(Employee*)

#endif // EMPLOYEE_H
