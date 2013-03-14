#-------------------------------------------------
#
# Project created by QtCreator 2013-03-14T13:11:10
#
#-------------------------------------------------

QT       += core gui

TARGET = SII_IFD00x_USB_Printer

CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    item.cpp \
    reciept.cpp \
    recieptreader.cpp \
    printmanager.cpp

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

HEADERS += \
    item.h \
    reciept.h \
    recieptreader.h \
    printmanager.h
