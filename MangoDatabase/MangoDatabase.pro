#-------------------------------------------------
#
# Project created by QtCreator 2012-08-03T21:18:09
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = MangoDatabase
TEMPLATE = lib

DEFINES += MANGODATABASE_LIBRARY

SOURCES += mangodatabase.cpp \
    user.cpp \
    size.cpp \
    ordertype.cpp \
    orderdetail.cpp \
    order.cpp \
    itemdetail.cpp \
    itemcomponent.cpp \
    item.cpp \
    event.cpp \
    databasemanager.cpp \
    component.cpp \
    checkout.cpp \
    category.cpp \
    canceledorder.cpp \
    additional.cpp \
    helper.cpp

HEADERS += mangodatabase.h\
        MangoDatabase_global.h \
    user.h \
    size.h \
    ordertype.h \
    orderdetail.h \
    order.h \
    itemdetail.h \
    itemcomponent.h \
    item.h \
    event.h \
    databasemanager.h \
    component.h \
    checkout.h \
    category.h \
    canceledorder.h \
    additional.h \
    helper.h


OTHER_FILES += \
    MangoDatabase.pro.user


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

LIBS += -L$$PWD/../bin/ -lMangoModel

