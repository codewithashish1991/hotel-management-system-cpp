#-------------------------------------------------
#
# Project created by QtCreator 2014-09-02T03:25:20
#
#-------------------------------------------------

QT       += core gui
QT     += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HotelMS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chgpwd.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    chgpwd.h \
    login.h \
    databaseconnection.h

FORMS    += mainwindow.ui \
    chgpwd.ui \
    login.ui
