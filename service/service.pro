TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt




SOURCES += \
        ../Utils/mqhelper.cpp \
        ../Utils/shmhelper.cpp \
        datahelper.cpp \
        main.cpp \
        mainservice.cpp


HEADERS += \
    ../Utils/CommonDefine.h \
    ../Utils/mqhelper.h \
    ../Utils/shmhelper.h \
    DataDefine.h \
    ServiceDefine.h \
    datahelper.h \
    mainservice.h

LIBS += -lrt \
        -lpthread

DISTFILES +=
