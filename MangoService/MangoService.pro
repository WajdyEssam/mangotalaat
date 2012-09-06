#-------------------------------------------------
#
# Project created by QtCreator 2012-08-03T22:08:35
#
#-------------------------------------------------

QT       -= gui
QT += phonon

TARGET = MangoService
TEMPLATE = lib

DEFINES += MANGOSERVICE_LIBRARY

SOURCES += mangoservice.cpp \
    user.cpp \
    size.cpp \
    ordertype.cpp \
    orderdetail.cpp \
    order.cpp \
    itemdetail.cpp \
    itemcomponent.cpp \
    item.cpp \
    helper.cpp \
    event.cpp \
    component.cpp \
    checkout.cpp \
    category.cpp \
    canceledorder.cpp \
    additional.cpp \
    sugar.cpp \
    componentprice.cpp \
    receiptprinter.cpp

HEADERS += mangoservice.h\
        MangoService_global.h \
    user.h \
    size.h \
    ordertype.h \
    orderdetail.h \
    order.h \
    itemdetail.h \
    itemcomponent.h \
    item.h \
    helper.h \
    event.h \
    component.h \
    checkout.h \
    category.h \
    canceledorder.h \
    additional.h \
    sugar.h \
    componentprice.h \
    receiptprinter.h

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
LIBS += -L$$PWD/../bin/ -lMangoDatabase

