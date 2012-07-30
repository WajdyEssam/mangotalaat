#-------------------------------------------------
#
# Project created by QtCreator 2012-07-13T14:23:46
#
#-------------------------------------------------

QT       += core gui sql declarative

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
    ui/orderwidget.cpp \
    ui/itempropertiesdialog.cpp \
    model/additionals.cpp \
    model/order.cpp \
    ui/SlidingStackedWidget.cpp \
    model/orderobject.cpp \
    report/loginreport.cpp \
    report/orderreport.cpp \
    report/cancelreport.cpp \
    report/user.cpp \
    ui/propertywidget.cpp \
    ui/toolbutton.cpp

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
    ui/orderwidget.h \
    model/itemdetail.h \
    ui/itempropertiesdialog.h \
    model/additionals.h \
    model/order.h \
    ui/SlidingStackedWidget.h \
    model/orderobject.h \
    report/loginreport.h \
    report/orderreport.h \
    report/cancelreport.h \
    report/user.h \
    ui/propertywidget.h \
    ui/toolbutton.h

FORMS += \
    ui/itempropertiesdialog.ui


RESOURCES += \
    resources.qrc

OTHER_FILES += \
    mango.qss \
    ui/qml/orderlist.qml





























