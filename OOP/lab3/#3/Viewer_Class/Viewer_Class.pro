#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T21:15:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Viewer_Class
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    matrix.cpp \
    line.cpp \
    vertex.cpp \
    model.cpp \
    camera.cpp \
    compositeobject.cpp \
    visiblemodification.cpp \
    loader.cpp \
    filemanager.cpp \
    vertexmodifications.cpp \
    drawer.cpp \
    canvas.cpp \
    message.cpp \
    scene.cpp \
    painter.cpp \
    modifier.cpp \
    planner.cpp \
    keeper.cpp

HEADERS  += mainwindow.h \
    b_error.h \
    matrix.h \
    b_object.h \
    visibleobject.h \
    invisibleobject.h \
    b_model.h \
    line.h \
    vertex.h \
    model.h \
    camera.h \
    compositeobject.h \
    b_modification.h \
    visiblemodification.h \
    invisiblemodification.h \
    b_manager.h \
    loader.h \
    sourcemanager.h \
    filemanager.h \
    fileerrors.h \
    memoryerrors.h \
    vertexmodifications.h \
    drawer.h \
    b_canvas.h \
    canvas.h \
    canvaserrors.h \
    b_message.h \
    message.h \
    b_command.h \
    singleton.h \
    sceneerrors.h \
    scene.h \
    b_painter.h \
    cameramodifications.h \
    painter.h \
    vertexmodification.h \
    modifier.h \
    planner.h \
    planercommand.h \
    planercommands.h \
    keeper.h

FORMS    += mainwindow.ui
