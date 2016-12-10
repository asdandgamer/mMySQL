#-------------------------------------------------
#
# Project created by QtCreator 2016-12-05T01:04:45
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mMySQL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connectiondatadialog.cpp \
    globals.cpp

HEADERS  += mainwindow.h \
    connectiondatadialog.h \
    globals.h

FORMS    += mainwindow.ui \
    connectiondatadialog.ui

DISTFILES +=
