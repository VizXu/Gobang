#-------------------------------------------------
#
# Project created by QtCreator 2018-03-22T19:55:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gobangGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gobangclient.cpp \
    debug.cpp \
    gameinfo.cpp \
    gobang.cpp

HEADERS  += mainwindow.h \
    gobangclient.h \
    debug.h \
    gameinfo.h \
    gobang.h
