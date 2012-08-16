#-------------------------------------------------
#
# Project created by QtCreator 2012-08-03T21:26:41
#
#-------------------------------------------------

QT       -= gui

TARGET = MangoModel
TEMPLATE = lib

DEFINES += MANGOMODEL_LIBRARY

SOURCES += mangomodel.cpp \
    itemdetail.cpp \
    itemcomponent.cpp \
    item.cpp \
    event.cpp \
    component.cpp \
    checkout.cpp \
    category.cpp \
    canceledorder.cpp \
    baseitem.cpp \
    additional.cpp \
    user.cpp \
    size.cpp \
    ordertype.cpp \
    orderobject.cpp \
    orderdetail.cpp \
    order.cpp \
    sugar.cpp

HEADERS += mangomodel.h\
        MangoModel_global.h \
    itemdetail.h \
    itemcomponent.h \
    item.h \
    event.h \
    component.h \
    checkout.h \
    category.h \
    canceledorder.h \
    baseitem.h \
    additional.h \
    user.h \
    size.h \
    ordertype.h \
    orderobject.h \
    orderdetail.h \
    order.h \
    sugar.h

unix:DESTDIR = ../bin
unix:OBJECTS_DIR = build/_obj
unix:MOC_DIR = build/_moc
unix:RCC_DIR = build/_rcc
unix:UI_DIR = build/_ui

win32:DESTDIR = ../bin
win32:OBJECTS_DIR = build/_obj
win32:MOC_DIR = build/_moc
win32:RCC_DIR = build/_rcc
win32:UI_DIR = build/_ui
