#-------------------------------------------------
#
# Project created by QtCreator 2012-07-13T14:23:46
#
#-------------------------------------------------

QT       += core gui sql declarative webkit

TARGET = Mango
TEMPLATE = app

SOURCES += main.cpp\
    ui/categorieswidget.cpp \
    ui/mainwindow.cpp \
    ui/sizewidget.cpp \
    ui/itemswidget.cpp \
    ui/headerwidget.cpp \
    ui/orderwidget.cpp \
    ui/SlidingStackedWidget.cpp \
    ui/propertywidget.cpp \
    ui/toolbutton.cpp \
    ui/keypaddialog.cpp \
    ui/aboutdialog.cpp \
    ui/invoiceveiwerwidget.cpp \
    ui/loggindialog.cpp \
    ui/returnorderdialog.cpp \
    ui/selectperiddialog.cpp \
    ui/sugardialog.cpp

HEADERS  += ui/categorieswidget.h \
    ui/mainwindow.h \
    ui/sizewidget.h \
    ui/itemswidget.h \
    ui/headerwidget.h \
    ui/orderwidget.h \
    ui/SlidingStackedWidget.h \
    ui/toolbutton.h \
    ui/propertywidget.h \
    ui/keypaddialog.h \
    ui/aboutdialog.h \
    ui/invoiceveiwerwidget.h \
    ui/loggindialog.h \
    ui/returnorderdialog.h \
    ui/selectperiddialog.h \
    ui/sugardialog.h

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    mango.qss \
    ui/qml/orderlist.qml

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
LIBS += -L$$PWD/../bin/ -lMangoService
LIBS += -L$$PWD/../bin/ -lMangoReports

FORMS += \
    ui/aboutdialog.ui \
    ui/invoiceveiwerwidget.ui \
    ui/loggindialog.ui \
    ui/returnorderdialog.ui \
    ui/selectperiddialog.ui

