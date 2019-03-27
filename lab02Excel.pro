#-------------------------------------------------
#
# Project created by QtCreator 2018-10-13T15:21:38
#
#-------------------------------------------------

QT       += core gui

QT += xlsx

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab02Excel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    helpwindow.cpp \
    aboutwindow.cpp

HEADERS  += mainwindow.h \
    helpwindow.h \
    aboutwindow.h

FORMS    += mainwindow.ui \
    helpwindow.ui \
    aboutwindow.ui
