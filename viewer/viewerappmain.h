#ifndef VIEWERAPPMAIN_H
#define VIEWERAPPMAIN_H

#include <QObject>
#include <QQmlEngine>
#include <QQuickView>
#include <QQmlApplicationEngine>
#include <listmodel.h>
#include <messagequeue.h>

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

private:
    QQuickView* m_view;
    QQuickItem* m_rootObject;
    QQmlApplicationEngine* m_engine;
    ListModel* m_model ;
    MessageQueue* m_messageQueue;
};

#endif // VIEWERAPPMAIN_H
