TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    libro.cpp \
    libreria.cpp

include(deployment.pri)
qtcAddDeployment()

INCLUDEPATH += ./include

CONFIG += c++11

HEADERS += \
    libro.h \
    libreria.h

