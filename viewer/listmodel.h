#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
//#include <QAbstractProxyModel>
#include "../Utils/employee.h"

class ListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ListModel(QObject *parent = nullptr);
    virtual ~ListModel() override;

    enum E_ROLES {
        E_ROLE_NAME,
        E_ROLE_AVERAGE,
        E_ROLE_ID,
    };

public:

    // Basic functionality:

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setList(const QList<Employee*> &list);
    QList<Employee*> getList() const;
    Q_INVOKABLE int getCount();
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<Employee*> m_list;
    QHash<int, QByteArray> m_roleNames;
};

#endif // LISTMODEL_H
