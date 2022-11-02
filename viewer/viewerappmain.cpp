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
    this->registerDataType();
    this->connectBetweenMqAndMain();
    this->connectBetweenGUI();
    m_shm = new ShareMemory();
    this->requestFullList();
}

ViewerAppMain::~ViewerAppMain()
{

}

void ViewerAppMain::listSearch(QString inp)
{
    std::cout << "listSearch: " << inp.toStdString() << std::endl;
    m_messageQueue->searchText(inp);
}

void ViewerAppMain::queryData(int id)
{
    std::cout << "queryData: " << id << std::endl;
    m_messageQueue->queryForId(id);
}

void ViewerAppMain::requestFullList()
{
    m_messageQueue->requestFullList();
}



void ViewerAppMain::initView()
{
    m_engine = new QQmlApplicationEngine();
    QQmlContext* ctxt = m_engine->rootContext();
    ctxt->setContextProperty("employeeModel", m_model);
    ctxt->setContextProperty("appMain", this);
    m_engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    m_rootObject = m_engine->rootObjects().first();
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
    connect(m_messageQueue, SIGNAL(sigDataChanged(int)),
            this, SLOT(onSigDataChanged(int)));
    connect(m_messageQueue, SIGNAL(sigEmployeeData(EmployeeGrade)),
            this, SLOT(onSigEmployeeData(EmployeeGrade)));
}

void ViewerAppMain::connectBetweenGUI()
{
    connect(this,SIGNAL(sigUpdateData(QString,int,int,int,int,int,int)),
           m_rootObject, SIGNAL(sigUpdateDataOnQML(QString,int,int,int,int,int,int)));
    connect(this, SIGNAL(sigListChanged())
            ,m_rootObject, SIGNAL(sigListChangedOnQML()));
}

void ViewerAppMain::registerDataType()
{
    qRegisterMetaType<EmployeeGrade>("EmployeeGrade");
}

void ViewerAppMain::onSigDataChanged(int num)
{
    std::cout << "receiving3" << std::endl;
    m_eData.clear();
    m_eData = m_shm->readData(num);
    QList<Employee*> list;
    for (int i = 0; i < num; i++) {
        list.append(new Employee(m_eData[i].name, m_eData[i].average, m_eData[i].id));
    }
    m_model->setList(list);
    emit this->sigListChanged();
}

void ViewerAppMain::onSigEmployeeData(EmployeeGrade grade)
{
    QString _name = QString::fromStdString(grade.eName);
    emit this->sigUpdateData(_name, grade.grade[0], grade.grade[1], grade.grade[2], grade.grade[3]
            , grade.grade[4], grade.grade[ID_INDEX]);
}
