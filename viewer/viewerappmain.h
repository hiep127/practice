#ifndef VIEWERAPPMAIN_H
#define VIEWERAPPMAIN_H

#include "sharememory.h"
#include <QObject>
#include <QQmlEngine>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <listmodel.h>
#include <messagequeue.h>
#include </home/avn/practice/Utils/mqhelper.h>
#include </home/avn//practice/Utils/IPCDefine.h>
#include </home/avn//practice/Utils/shmhelper.h>


class ViewerAppMain : public QObject
{
    Q_OBJECT
public:
    ViewerAppMain();
    ~ViewerAppMain();

    Q_INVOKABLE void listSearch(QString inp);
    int getCount();


private:
    void initView();
    void initModel();
    void connectBetweenMqAndMain();
    void listDataChange();

private slots:
    void onSigDataChanged();

private:
    QQuickView* m_view;
    QQuickItem* m_rootObject;
    QQmlApplicationEngine* m_engine;
    ListModel* m_model ;
    MessageQueue* m_messageQueue;
    ShareMemory* m_shm;
    std::vector<EmployeeData> m_eData;

};

#endif // VIEWERAPPMAIN_H
