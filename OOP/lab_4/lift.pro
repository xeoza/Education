#-------------------------------------------------
#
# Project created by QtCreator 2018-05-21T19:54:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lift
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    button.cpp \
    cabin.cpp \
    controller.cpp \
    doors.cpp \
    lift.cpp

HEADERS  += mainwindow.h \
    button.h \
    cabin.h \
    controller.h \
    doors.h \
    lift.h

FORMS    += mainwindow.ui
