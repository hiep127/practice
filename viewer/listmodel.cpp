#include "listmodel.h"
#include "../Utils/employee.cpp"
#include <QDebug>

ListModel::ListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_roleNames[E_ROLE_NAME] = "employeeName";
    m_roleNames[E_ROLE_AVERAGE] = "average";
}

ListModel::~ListModel()
{
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    return m_list.count();
}



QVariant ListModel::data(const QModelIndex &index, int role) const
{
    QVariant m_element;
    if (!index.isValid() || index.row() < 0 || index.row() >= m_list.size()) {
        m_element = QVariant();
    } else {
        int row = index.row();
        Employee* element = m_list[row];
        switch (role) {
        case E_ROLE_NAME:
            m_element = element->employeeName();
            break;
        case E_ROLE_AVERAGE:
            m_element = element->average();
            break;
        default:
            break;
        }
    }
    return m_element;
}



void ListModel::setList(const QList<Employee*> &list)
{
    qDebug() << list.count();
    beginResetModel();
    m_list.clear();
    m_list = list;
    endResetModel();
}

QList<Employee *> ListModel::getList() const
{
    return m_list;
}

int ListModel::getCount()
{
    return m_list.count();
}

//QVariantMap ListModel::get(int row) const
//{
//    QHash<int, QByteArray> names = roleNames();
//    QHashIterator<int, QByteArray> i(names);
//    QVariantMap res;
//    QModelIndex idx = index(row, 0);
//    //qDebug() << m_list.count();
//    while(i.hasNext()) {
//        i.next();
//        QVariant data = idx.data(i.key());
//        res[i.value()] = data;

//    }
//    qDebug() << res;
//    return res;
//}

QHash<int, QByteArray> ListModel::roleNames() const
{
    return m_roleNames;
}
