#-------------------------------------------------
#
# Project created by QtCreator 2017-05-17T11:29:33
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtstart
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        ../src/ProgramHandler.cpp\
        ../src/FileHandler.cpp

HEADERS  += mainwindow.h\
         ../inc/ProgramHandler.h\
         ../inc/FileHandler.h

FORMS    += mainwindow.ui
