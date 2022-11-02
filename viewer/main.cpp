#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "EditorAppMain.h"
#include <QQmlContext>
#include "listmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
//    ListModel model;

//    QList<Employee*> list;
//    list.append(new Employee("hiep", 2));
//    list.append(new Employee("hiep", 2));
//    list.append(new Employee("hiep", 2));
//    list.append(new Employee("hiep", 2));
//    list.append(new Employee("hiep", 2));


//    QQmlApplicationEngine engine;
//    QQmlContext* ctxt = engine.rootContext();
//    ctxt->setContextProperty("employeeModel", &model);
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    model.setList(list);
//    if (engine.rootObjects().isEmpty())
//        return -1;
    EditorAppMain appmain;
    return app.exec();
}
