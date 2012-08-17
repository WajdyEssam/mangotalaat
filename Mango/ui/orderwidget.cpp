#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeItem>
#include <QVBoxLayout>
#include <QUrl>
#include <QGroupBox>
#include <QPushButton>
#include <QLCDNumber>

#include <QDebug>

#include "orderwidget.h"
#include "../../MangoModel/orderobject.h"
#include "../../MangoModel/orderdetail.h"

OrderWidget::OrderWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedWidth(380);
    this->setObjectName("orderWidget");

    layout = new QVBoxLayout(this);

    m_lcd = new QLCDNumber;
    m_lcd->display(0);

    initOrderList();
    initOrderCommand();
}

int OrderWidget::totalCash() const
{
    return (int)m_lcd->value();
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
    box->setTitle("سلة المشتريات");

    QHBoxLayout* upperLayout = new QHBoxLayout;
    upperLayout->addWidget(m_declarativeView);

    box->setLayout(upperLayout);
    layout->addWidget(box);
}

void OrderWidget::initOrderCommand()
{
    QGroupBox* box = new QGroupBox;
    box->setTitle("حساب الطلب");


    QPushButton* applyButton = new QPushButton;
    applyButton->setStyleSheet("QPushButton { border-width: 4px; border-image: url(:/images/apply_order.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px; } QPushButton:hover { border-width: 4px; border-image: url(:/images/apply_order_hover.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;} QPushButton:pressed, #orderWidget QPushButton:checked { border-width: 4px; border-image: url(:/images/apply_order_pressed.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;}");

    QPushButton* cancelButton = new QPushButton;
    cancelButton->setStyleSheet("QPushButton { border-width: 4px; border-image: url(:/images/cancel_order.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px; } QPushButton:hover { border-width: 4px; border-image: url(:/images/cancel_order_hover.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;} QPushButton:pressed, #orderWidget QPushButton:checked { border-width: 4px; border-image: url(:/images/cancel_order_pressed.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;}");

    QPushButton* discountButton = new QPushButton;
    discountButton->setStyleSheet("QPushButton { border-width: 4px; border-image: url(:/images/discount_order.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px; } QPushButton:hover { border-width: 4px; border-image: url(:/images/discount_order_hover.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;} QPushButton:pressed, #orderWidget QPushButton:checked { border-width: 4px; border-image: url(:/images/discount_order_pressed.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;}");

    QPushButton* cobonButton = new QPushButton;
    cobonButton->setStyleSheet("QPushButton { border-width: 4px; border-image: url(:/images/cobon_order.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px; } QPushButton:hover { border-width: 4px; border-image: url(:/images/cobon_order_hover.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;} QPushButton:pressed, #orderWidget QPushButton:checked { border-width: 4px; border-image: url(:/images/cobon_order_pressed.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;}");


    applyButton->setMaximumSize(163, 54);
    cancelButton->setMaximumSize(163, 54);
    discountButton->setMaximumSize(163, 54);
    cobonButton->setMaximumSize(163, 54);

    connect(applyButton, SIGNAL(clicked()), this, SIGNAL(applyClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SIGNAL(cancelClicked()));
    connect(discountButton, SIGNAL(clicked()), this, SIGNAL(applyDiscountClicked()));

    QGridLayout* gridLayout = new QGridLayout;
    gridLayout->addWidget(m_lcd, 0, 2, 2, 1);
    gridLayout->addWidget(applyButton, 0, 0);
    gridLayout->addWidget(cancelButton, 0 ,1);
    gridLayout->addWidget(discountButton, 1, 0);
    gridLayout->addWidget(cobonButton, 1, 1);

    box->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Maximum);
    box->setLayout(gridLayout);

    layout->addWidget(box);
}

void OrderWidget::updateLCDTotalCash(QList<Model::OrderDetail> orderDetails)
{
    int cash = 0;

    foreach(Model::OrderDetail order, orderDetails) {
        cash += order.cash();
    }

    m_lcd->display(cash);
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

    updateLCDTotalCash(orderDetails);

}
