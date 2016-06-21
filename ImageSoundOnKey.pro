#-------------------------------------------------
#
# Project created by QtCreator 2016-05-12T19:10:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageSoundOnKey
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myqwidget.cpp

HEADERS  += mainwindow.h \
    myqwidget.h

FORMS    += mainwindow.ui

CONFIG +=C++11
QT += multimedia
