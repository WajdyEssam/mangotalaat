#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeItem>
#include <QVBoxLayout>
#include <QUrl>
#include <QGroupBox>
#include <QPushButton>
#include <QLCDNumber>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

#include "orderwidget.h"
#include "discountdialog.h"

#include "../../MangoModel/orderobject.h"
#include "../../MangoModel/orderdetail.h"

#include "../../MangoService/order.h"
#include "../../MangoService/helper.h"
#include "../../MangoService/receiptprinter.h"

#include "../language.h"

OrderWidget::OrderWidget(int userId, QWidget *parent) :
    QWidget(parent), m_userId(userId)
{
    this->setFixedWidth(340);
    this->setObjectName("orderWidget");

    layout = new QVBoxLayout(this);

    initOrderList();
    initOrderCommand();

    connect(&m_cartOrder, SIGNAL(cartOrderUpdated()), this, SLOT(updateQMLCart()));
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
    connect(item, SIGNAL(itemClick(QString)), SLOT(orderItemClick(QString)));

    QGroupBox* box = new QGroupBox;
    box->setTitle(tr("Shopping cart"));

    QHBoxLayout* upperLayout = new QHBoxLayout;
    upperLayout->addWidget(m_declarativeView);

    box->setLayout(upperLayout);
    layout->addWidget(box);
}

void OrderWidget::initOrderCommand()
{
    QGroupBox* totalCashGroup = new QGroupBox(tr("Total Cash"));
    m_totalCashLCD = new QLCDNumber;
    m_totalCashLCD->display(0);
    QVBoxLayout* totalCashVBoxLayout = new QVBoxLayout;
    totalCashVBoxLayout->addWidget(m_totalCashLCD);
    totalCashGroup->setLayout(totalCashVBoxLayout);

    QGroupBox* discountGroup = new QGroupBox(tr("Discount"));
    m_discountLCD = new QLCDNumber;
    m_discountLCD->display(0);
    m_discountLCD->setStyleSheet("color: red;");
    QVBoxLayout* discountVBoxLayout = new QVBoxLayout;
    discountVBoxLayout->addWidget(m_discountLCD);
    discountGroup->setLayout(discountVBoxLayout);

    QGroupBox* box = new QGroupBox;
    box->setTitle(tr("Checkout Order"));

    QPushButton* applyButton = new QPushButton;
    applyButton->setStyleSheet("QPushButton { border-width: 4px; border-image: url(:/images/apply_order_ar.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px; } QPushButton:hover { border-width: 4px; border-image: url(:/images/apply_order_hover_ar.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;} QPushButton:pressed, #orderWidget QPushButton:checked { border-width: 4px; border-image: url(:/images/apply_order_pressed_ar.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;}");
    QPushButton* cancelButton = new QPushButton;
    cancelButton->setStyleSheet("QPushButton { border-width: 4px; border-image: url(:/images/cancel_order_ar.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px; } QPushButton:hover { border-width: 4px; border-image: url(:/images/cancel_order_hover_ar.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;} QPushButton:pressed, #orderWidget QPushButton:checked { border-width: 4px; border-image: url(:/images/cancel_order_pressed_ar.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;}");
    QPushButton* discountButton = new QPushButton;
    discountButton->setStyleSheet("QPushButton { border-width: 4px; border-image: url(:/images/discount_order_ar.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px; } QPushButton:hover { border-width: 4px; border-image: url(:/images/discount_order_hover_ar.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;} QPushButton:pressed, #orderWidget QPushButton:checked { border-width: 4px; border-image: url(:/images/discount_order_pressed_ar.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;}");
    //QPushButton* cobonButton = new QPushButton;
    //cobonButton->setStyleSheet("QPushButton { border-width: 4px; border-image: url(:/images/cobon_order_ar.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px; } QPushButton:hover { border-width: 4px; border-image: url(:/images/cobon_order_hover_ar.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;} QPushButton:pressed, #orderWidget QPushButton:checked { border-width: 4px; border-image: url(:/images/cobon_order_pressed_ar.png) 4 4 4 4 stretch stretch; min-width: 32px; min-height: 32px;}");

    applyButton->setFixedSize(140, 40);
    cancelButton->setFixedSize(140, 40);
    discountButton->setFixedSize(140, 40);
    //cobonButton->setMaximumSize(163, 54);

    connect(applyButton, SIGNAL(clicked()), this, SLOT(applyOrderClicked()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelOrderClicked()));
    connect(discountButton, SIGNAL(clicked()), this, SLOT(addDiscountClicked()));

    QGridLayout* gridLayout = new QGridLayout;
    gridLayout->addWidget(applyButton, 0, 0);
    gridLayout->addWidget(cancelButton, 1 ,0);
    gridLayout->addWidget(discountButton, 2, 0);
    //gridLayout->addWidget(cobonButton, 1, 1);

    gridLayout->addWidget(totalCashGroup, 0, 1, 3, 1);
    gridLayout->addWidget(discountGroup, 0, 2, 3, 1);

    box->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Maximum);
    box->setLayout(gridLayout);

    layout->addWidget(box);
}

void OrderWidget::clearShoppingCart()
{
    m_cartOrder.clear();
    Services::Helper::runSoundFile(Services::Helper::clearSoundFile);
}

void OrderWidget::updateQMLCart()
{
    QList<QObject*> orderList;

    foreach (Model::OrderDetail orderDetail, m_cartOrder.orderDetails()) {
        OrderObject* orderObject = new OrderObject(
                    orderDetail.itemDetail().id(),
                    orderDetail.orderIndexId(),
                    Settings::Language::getCurrentLanguage() == Settings::Language::Arabic ? orderDetail.itemDetail().item().arabicName() : orderDetail.itemDetail().item().englishName(),
                    Settings::Language::getCurrentLanguage() == Settings::Language::Arabic ? orderDetail.itemDetail().size().arabicName() : orderDetail.itemDetail().size().englishName(),
                    QString::number(orderDetail.cash()),
                    orderDetail.itemDetail().item().category().id());

        orderList.append(orderObject);
    }

    QDeclarativeContext* context = m_declarativeView->rootContext();
    context->setContextProperty("ordersModel", QVariant::fromValue(orderList));

    updateLCDTotalCash();
}

void OrderWidget::updateLCDTotalCash()
{
    m_totalCashLCD->display(m_cartOrder.totalCashAfterDiscount());
    m_discountLCD->display(m_cartOrder.discount());
}

void OrderWidget::addItemToCart(Model::OrderDetail order)
{
    this->m_cartOrder.add(order);
    Services::Helper::runSoundFile(Services::Helper::addingSoundFile);
    emit showHomePage();
}

void OrderWidget::updateItemInCart(Model::OrderDetail oldOrder)
{
    this->m_cartOrder.update(oldOrder);
    Services::Helper::runSoundFile(Services::Helper::addingSoundFile);
    emit showHomePage();
}

void OrderWidget::removeItemFromCart(Model::OrderDetail oldOrder)
{
    this->m_cartOrder.remove(oldOrder);
    Services::Helper::runSoundFile(Services::Helper::removeSoundFile);
    emit showHomePage();
}

void OrderWidget::applyOrderClicked()
{
    if (this->m_cartOrder.isEmpty()) {
        QMessageBox::information(this, tr("Shopping cart is empty"), tr("There is no item in the shopping cart!"));
            return;
    }

    QMessageBox::StandardButton button = QMessageBox::information(this,
          tr("Apply the order"),
          tr("Are you sure you want to apply the order and print the invoice?"),
          QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (button == QMessageBox::No)
        return;

    applyOrder();
}

void OrderWidget::cancelOrderClicked()
{
    if (this->m_cartOrder.isEmpty()) {
            QMessageBox::information(this, tr("Shopping cart is empty"), tr("There is no item in the shopping cart!"));
            return;
    }

    QMessageBox::StandardButton button = QMessageBox::warning(this,
          tr("Cancel the order"),
          tr("Are you sure you want to cancel the order?"),
          QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (button == QMessageBox::No)
        return;

    clearShoppingCart();
    emit showHomePage();
}

void OrderWidget::addDiscountClicked()
{
    if (this->m_cartOrder.isEmpty()) {
            QMessageBox::information(this, tr("Shopping cart is empty"), tr("There is no item in the shopping cart!"));
            return;
    }

    int discount = 0;
    Model::OrderType::OrderTypes orderType = Model::OrderType::DISCOUNT_VALUE;

    DiscountDialog dlg(m_cartOrder.totalCashBeforeDiscount());
    if (dlg.exec() == QDialog::Accepted) {
        discount = dlg.discount();
        orderType = dlg.orderType();

        m_cartOrder.setDiscount(discount);
        m_cartOrder.setOrderType(orderType);
    }
}

void OrderWidget::orderItemClick(QString indexId)
{
    emit orderItemClick(m_cartOrder.getOrderByIndexId(indexId));
}

void OrderWidget::applyOrder()
{
    if (m_cartOrder.isEmpty())
        return;

    Model::Order order(0,
                       QDateTime::currentDateTime(),
                       m_cartOrder.orderType(),
                       m_cartOrder.totalCashBeforeDiscount(),
                       m_cartOrder.discount(),
                       m_cartOrder.totalCashAfterDiscount(),
                       0,
                       m_userId);

    bool ret = Services::Order::add(order, m_cartOrder.orderDetails());

    if ( ret ) {
        Services::Helper::runSoundFile(Services::Helper::checkoutSoundFile);

        Services::ReceiptPrinter printer;

        printer.print(&m_cartOrder);

        clearShoppingCart();
    }

    emit showHomePage();
    QMessageBox::information(this, tr("Operation done successully"), tr("System is ready to accept new orders"), QMessageBox::Ok, QMessageBox::Ok);
}

