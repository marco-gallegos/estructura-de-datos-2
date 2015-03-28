TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    libro.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    libro.h

