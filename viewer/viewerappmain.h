#ifndef ViewerAppMain_H
#define ViewerAppMain_H

#include "sharememory.h"
#include <QObject>
#include <QQmlEngine>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <listmodel.h>
#include <messagequeue.h>
#include <../Utils/mqhelper.h>
#include <../Utils/CommonDefine.h>
#include <../Utils/shmhelper.h>


class ViewerAppMain : public QObject
{
    Q_OBJECT
public:
    ViewerAppMain();
    ~ViewerAppMain();

    Q_INVOKABLE void listSearch(QString inp);
    Q_INVOKABLE void queryData(int id);
    Q_INVOKABLE void requestFullList();
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
    void sigListChanged();

private slots:
    void onSigDataChanged(int num);
    void onSigEmployeeData(EmployeeGrade grade);
private:
    QQuickView* m_view;
    QObject* m_rootObject;
    QQmlApplicationEngine* m_engine;
    ListModel* m_model ;
    MessageQueue* m_messageQueue;
    ShareMemory* m_shm;
    std::vector<EmployeeData> m_eData;

};

#endif // ViewerAppMain_H
