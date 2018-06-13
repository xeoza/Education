#-------------------------------------------------
#
# Project created by QtCreator 2018-03-10T18:28:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lab_01
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    planner.cpp \
    actions.cpp \
    calculation.cpp \
    drawing.cpp \
    add_calc.cpp

HEADERS  += mainwindow.h \
    planner.h \
    actions.h \
    calculation.h \
    drawing.h \
    add_calc.h

FORMS    += mainwindow.ui
