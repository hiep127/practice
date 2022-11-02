#include "viewerappmain.h"
#include <QQuickItem>
#include <stdio.h>
#include <iostream>
#include <QQmlContext>

ViewerAppMain::ViewerAppMain()
{
    //m_rootObject = nullptr;
    m_view = nullptr;
    m_model = new ListModel();
    this->initView();
    this->initModel();
    m_messageQueue = new MessageQueue();
    this->registerDataType();
    this->connectBetweenMqAndMain();
    this->connectBetweenGUI();
    m_shm = new ShareMemory();
}

ViewerAppMain::~ViewerAppMain()
{

}

void ViewerAppMain::listSearch(QString inp)
{

}

void ViewerAppMain::queryData(int id)
{
    m_messageQueue->searchForId(id);
}



void ViewerAppMain::initView()
{
    m_engine = new QQmlApplicationEngine();
    QQmlContext* ctxt = m_engine->rootContext();
    ctxt->setContextProperty("employeeModel", m_model);
    ctxt->setContextProperty("appMain", this);
    m_engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    m_rootObject = m_engine->rootObjects();
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
    connect(m_messageQueue, SIGNAL(sigEmployeeData(EmployeeGrade)),
            this, SLOT(onSigEmployeeData(EmployeeGrade)));
}

void ViewerAppMain::connectBetweenGUI()
{
    connect(this,SIGNAL(sigUpdateData(QString,int,int,int,int,int,int)),
            m_rootObject.first(), SIGNAL(sigUpdateDataOnQML(QString,int,int,int,int,int,int)));
}

void ViewerAppMain::registerDataType()
{
    qRegisterMetaType<EmployeeData>("EmployeeData");
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

void ViewerAppMain::onSigEmployeeData(EmployeeGrade grade)
{
    QString _name = QString::fromStdString(grade.eName);
    emit this->sigUpdateData(_name, grade.grade[0], grade.grade[1], grade.grade[2], grade.grade[3]
            , grade.grade[4], grade.grade[ID_INDEX]);
}
