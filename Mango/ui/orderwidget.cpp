#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeItem>
#include <QVBoxLayout>
#include <QUrl>
#include <QGroupBox>
#include <QPushButton>
#include <QDebug>

#include "orderwidget.h"
#include "../../MangoModel/orderobject.h"
#include "../../MangoModel/orderdetail.h"

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

    QDeclarativeItem *item = qobject_cast<QDeclarativeItem *>(m_declarativeView->rootObject());
    connect(item, SIGNAL(itemClick(QString)), SIGNAL(orderItemClick(QString)));

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

    connect(applyButton, SIGNAL(clicked()), this, SIGNAL(applyClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SIGNAL(cancelClicked()));

    contentLayout->addWidget(applyButton);
    contentLayout->addWidget(cancelButton);

    box->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Maximum);

    box->setLayout(contentLayout);
    lowerLayout->addWidget(box);

    layout->addLayout(lowerLayout);
}

void OrderWidget::updateOrderDetails(QList<Model::OrderDetail> orderDetails)
{
    QList<QObject*> orderList;

    foreach (Model::OrderDetail orderDetail, orderDetails) {
        OrderObject* orderObject = new OrderObject(
                    orderDetail.itemDetail().id(),
                    orderDetail.orderIndexId(),
                    orderDetail.itemDetail().item().arabicName(),
                    orderDetail.itemDetail().size().arabicName(),
                    QString::number(orderDetail.cash()),
                    orderDetail.itemDetail().item().category().id());

        orderList.append(orderObject);
    }

    qDebug() << "Number of orders: " << orderDetails.count();

    QDeclarativeContext* context = m_declarativeView->rootContext();
    context->setContextProperty("ordersModel", QVariant::fromValue(orderList));
}
