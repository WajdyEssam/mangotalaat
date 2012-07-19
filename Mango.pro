#-------------------------------------------------
#
# Project created by QtCreator 2012-07-13T14:23:46
#
#-------------------------------------------------

QT       += core gui sql

TARGET = Mango
TEMPLATE = app


SOURCES += main.cpp\
    model/category.cpp \
    model/component.cpp \
    model/item.cpp \
    database/databasemanager.cpp \
    ui/categorieswidget.cpp \
    ui/mainwindow.cpp \
    ui/sizewidget.cpp \
    ui/itemswidget.cpp \
    model/itemdetail.cpp \
    ui/headerwidget.cpp \
    ui/orderwidget.cpp

HEADERS  += model/category.h \
    model/component.h \
    model/item.h \
    database/databasemanager.h \
    ui/categorieswidget.h \
    ui/mainwindow.h \
    ui/sizewidget.h \
    model/itemdetail.h \
    ui/itemswidget.h \
    ui/headerwidget.h \
    ui/orderwidget.h

FORMS    += ui/categorieswidget.ui \
    ui/sizewidget.ui

RESOURCES += \
    resources.qrc

OTHER_FILES += \
    mango.qss














