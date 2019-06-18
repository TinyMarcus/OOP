#-------------------------------------------------
#
# Project created by QtCreator 2019-06-02T12:53:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab_04
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    facade/facade.cpp \
    object/camera.cpp \
    object/compositeobject.cpp \
    object/edge.cpp \
    object/model.cpp \
    object/node.cpp \
    scene/scene.cpp \
    workers/modelbuilder.cpp \
    workers/objecttransformator.cpp \
    managers/drawmanager.cpp \
    workers/modelio.cpp

HEADERS += \
        widget.h \
    actions/action.h \
    exceptions/baseexception.h \
    exceptions/builderexception.h \
    exceptions/drawerexception.h \
    exceptions/objectexception.h \
    exceptions/transformerexception.h \
    exceptions/ioexception.h \
    facade/facade.h \
    facade/controller.h \
    object/camera.h \
    object/compositeobject.h \
    object/edge.h \
    object/model.h \
    object/node.h \
    object/object.h \
    scene/scene.h \
    workers/modelbuilder.h \
    workers/objecttransformator.h \
    managers/drawmanager.h \
    managers/iomanager.h \
    managers/objectmanager.h \
    ui/drawer.h \
    transformations/transformations.h \
    workers/modelio.h \
    iterator/iterator.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
