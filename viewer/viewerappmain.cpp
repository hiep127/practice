#include "viewerappmain.h"
#include <QQuickItem>
#include <stdio.h>
#include <iostream>
#include <QQmlContext>

ViewerAppMain::ViewerAppMain()
{
    m_rootObject = nullptr;
    m_view = nullptr;
    m_model = new ListModel();
    initView();
    initModel();
    m_messageQueue = new MessageQueue();
}

ViewerAppMain::~ViewerAppMain()
{

}

void ViewerAppMain::listSearch(QString inp)
{

}



void ViewerAppMain::initView()
{
    m_engine = new QQmlApplicationEngine();
    QQmlContext* ctxt = m_engine->rootContext();
    ctxt->setContextProperty("employeeModel", m_model);
    ctxt->setContextProperty("appMain", this);
    m_engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
}

void ViewerAppMain::initModel()
{
    QList<Employee*> list;
    list.append(new Employee("hiep", 2));
    list.append(new Employee("hiep", 2));
    list.append(new Employee("hiep", 2));
    list.append(new Employee("hiep", 2));
    list.append(new Employee("hiep", 2));
    m_model->setList(list);
}
