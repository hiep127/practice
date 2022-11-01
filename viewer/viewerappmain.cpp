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
    this->initView();
    this->initModel();
    m_messageQueue = new MessageQueue();
    this->connectBetweenMqAndMain();
    m_shm = new ShareMemory();
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

void ViewerAppMain::connectBetweenMqAndMain()
{
    connect(m_messageQueue, SIGNAL(sigDataChanged()),
            this, SLOT(onSigDataChanged()));
}

void ViewerAppMain::onSigDataChanged()
{
    std::cout << "receiving3" << std::endl;
    m_eData = m_shm->readData();
    QList<Employee*> list;
    for (auto data : m_eData) {
        std::cout << data.name << std::endl;
        list.append(new Employee(data.name, data.average, data.id));
    }
    m_model->setList(list);
}
