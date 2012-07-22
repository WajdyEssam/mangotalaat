#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>
#include <QVBoxLayout>
#include <QUrl>
#include <QGroupBox>
#include <QPushButton>
#include <QDebug>

#include "orderwidget.h"
#include "model/orderobject.h"

OrderWidget::OrderWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedWidth(420);
    this->setObjectName("orderWidget");

    layout = new QVBoxLayout(this);

    initOrderList();
    initOrderCommand();
}

void OrderWidget::initOrderList()
{
    m_declarativeView = new QDeclarativeView;

    QDeclarativeContext* context = m_declarativeView->rootContext();
    context->setContextProperty("mycolor", QString("lightblue"));
    context->setContextProperty("ordersModel", QVariant::fromValue(QList<QObject*>()));

    m_declarativeView->setSource(QUrl("qrc:/ui/qml/orderlist.qml"));
    m_declarativeView->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    QGroupBox* box = new QGroupBox;
    box->setTitle("Shopping Cart");

    QHBoxLayout* upperLayout = new QHBoxLayout;
    upperLayout->addWidget(m_declarativeView);

    box->setLayout(upperLayout);
    layout->addWidget(box);
}

void OrderWidget::initOrderCommand()
{
    QHBoxLayout* lowerLayout = new QHBoxLayout;
    QGroupBox* box = new QGroupBox;
    box->setTitle("Order Command");

    QHBoxLayout* contentLayout = new QHBoxLayout;

    QPushButton* applyButton = new QPushButton;
    QPushButton* cancelButton = new QPushButton;

    contentLayout->addWidget(applyButton);
    contentLayout->addWidget(cancelButton);

    box->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Maximum);

    box->setLayout(contentLayout);
    lowerLayout->addWidget(box);

    layout->addLayout(lowerLayout);
}

void OrderWidget::updateOrders(QList<Model::Order> orders)
{
    QList<QObject*> orderList;

    foreach (Model::Order order, orders) {
        orderList.append(new OrderObject(1, QString("C++ item"), QString::number(order.getCash()), QString::number(order.getQunatity()), 5));
    }

    qDebug() << "Number of orders: " << orders.count();

    QDeclarativeContext* context = m_declarativeView->rootContext();
    context->setContextProperty("ordersModel", QVariant::fromValue(orderList));
}
