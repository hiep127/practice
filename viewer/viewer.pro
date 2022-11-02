QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../Utils/employee.cpp \
        ../Utils/mqhelper.cpp \
        ../Utils/shmhelper.cpp \
        listmodel.cpp \
        main.cpp \
        messagequeue.cpp \
        sharememory.cpp \
        EditorAppMain.cpp

RESOURCES += qml.qrc

INCLUDEPATH += "/practive/Utils"

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../Utils/IPCDefine.h \
    ../Utils/employee.h \
    ../Utils/mqhelper.h \
    ../Utils/shmhelper.h \
    listmodel.h \
    messagequeue.h \
    sharememory.h \
    EditorAppMain.h

LIBS += -lrt \
        -lpthread

DISTFILES += \
    ../image/C++.png \
    ../image/JS.png \
    ../image/QT.png \
    ../image/assembly.png \
    ../image/openGL.png \
    Loading.qml \
    SearchBox.qml

