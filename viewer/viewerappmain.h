#ifndef VIEWERAPPMAIN_H
#define VIEWERAPPMAIN_H

#include "sharememory.h"
#include <QObject>
#include <QQmlEngine>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <listmodel.h>
#include <messagequeue.h>
#include <../Utils/mqhelper.h>
#include <../Utils/IPCDefine.h>
#include <../Utils/shmhelper.h>


class ViewerAppMain : public QObject
{
    Q_OBJECT
public:
    ViewerAppMain();
    ~ViewerAppMain();

    Q_INVOKABLE void listSearch(QString inp);
    Q_INVOKABLE void queryData(int id);
    int getCount();


private:
    void initView();
    void initModel();
    void connectBetweenMqAndMain();
    void connectBetweenGUI();
    void listDataChange();
    void registerDataType();

signals:
    void sigUpdateData(QString name, int assemScore, int cScore, int jsScore, int qmlScore, int openGlScore, int id);

private slots:
    void onSigDataChanged();
    void onSigEmployeeData(EmployeeGrade grade);
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
