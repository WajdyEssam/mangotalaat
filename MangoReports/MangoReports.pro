#-------------------------------------------------
#
# Project created by QtCreator 2012-08-10T17:19:22
#
#-------------------------------------------------

QT       -= gui

TARGET = MangoReports
TEMPLATE = lib

DEFINES += MANGOREPORTS_LIBRARY

SOURCES += report.cpp \
    logginreport.cpp

HEADERS += report.h\
        MangoReports_global.h \
    logginreport.h

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
LIBS += -L$$PWD/../bin/ -lMangoService
