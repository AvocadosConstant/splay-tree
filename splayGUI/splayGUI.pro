#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T13:46:12
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = splayGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../splay.cpp

HEADERS  += mainwindow.h \
    ../node.h \
    ../splay.h

FORMS    += mainwindow.ui
