#-------------------------------------------------
#
# Project created by QtCreator 2013-04-26T21:47:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qtip
TEMPLATE = app


SOURCES += main.cpp\
        qtipdlg.cpp \
    qtimetool.cpp \
    qwelcomedlg.cpp \
    qclockthread.cpp

HEADERS  += qtipdlg.h \
    qtimetool.h \
    qwelcomedlg.h \
    qclockthread.h

FORMS    += qtipdlg.ui \
    qwelcomedlg.ui

RESOURCES += \
    style.qrc
