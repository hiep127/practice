TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../Utils/mqhelper.cpp \
        main.cpp

HEADERS += \
    ../Utils/IPCDefine.h \
    ../Utils/mqhelper.h

LIBS += -lrt \
        -lpthread
