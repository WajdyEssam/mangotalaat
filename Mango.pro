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
    ui/SlidingStackedWidget.cpp \
    model/orderobject.cpp \
    ui/propertywidget.cpp \
    ui/toolbutton.cpp \
    model/orderdetail.cpp \
    model/order.cpp \
    model/user.cpp \
    ui/keypaddialog.cpp \
    database/orderdetail.cpp \
    database/order.cpp \
    model/ordertype.cpp \
    database/ordertype.cpp \
    services/orderdetail.cpp \
    model/additional.cpp \
    model/baseitem.cpp \
    model/size.cpp \
    database/size.cpp \
    database/category.cpp \
    database/item.cpp \
    database/component.cpp \
    database/additional.cpp \
    database/user.cpp \
    model/event.cpp \
    database/event.cpp \
    services/helper.cpp \
    model/itemcomponent.cpp \
    database/itemcomponent.cpp \
    database/itemdetail.cpp \
    services/category.cpp \
    services/additional.cpp \
    services/component.cpp \
    services/size.cpp \
    services/ordertype.cpp \
    services/item.cpp \
    services/itemdetail.cpp \
    services/itemcomponent.cpp \
    services/order.cpp \
    model/checkout.cpp \
    database/checkout.cpp \
    services/checkout.cpp \
    services/event.cpp \
    services/user.cpp \
    database/canceledorder.cpp \
    model/canceledorder.cpp \
    services/canceledorder.cpp

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
    ui/SlidingStackedWidget.h \
    model/orderobject.h \
    ui/toolbutton.h \
    ui/propertywidget.h \
    model/orderdetail.h \
    model/order.h \
    model/user.h \
    model/constants.h \
    ui/keypaddialog.h \
    database/orderdetail.h \
    database/order.h \
    model/ordertype.h \
    database/ordertype.h \
    services/orderdetail.h \
    model/additional.h \
    model/baseitem.h \
    model/size.h \
    database/size.h \
    database/category.h \
    database/item.h \
    database/component.h \
    database/additional.h \
    database/user.h \
    model/event.h \
    database/event.h \
    services/helper.h \
    model/itemcomponent.h \
    database/itemcomponent.h \
    database/itemdetail.h \
    services/category.h \
    services/additional.h \
    services/component.h \
    services/size.h \
    services/ordertype.h \
    services/item.h \
    services/itemdetail.h \
    services/itemcomponent.h \
    services/order.h \
    model/checkout.h \
    database/checkout.h \
    services/checkout.h \
    services/event.h \
    services/user.h \
    database/canceledorder.h \
    model/canceledorder.h \
    services/canceledorder.h

FORMS +=


RESOURCES += \
    resources.qrc

OTHER_FILES += \
    mango.qss \
    ui/qml/orderlist.qml





























