#ifndef ORDERWIDGET_H
#define ORDERWIDGET_H

#include <QWidget>

#include "../../MangoModel/orderdetail.h"
#include "../../MangoModel/cartorder.h"

class QDeclarativeView;
class QVBoxLayout;
class QLCDNumber;
class QGroupBox;

class OrderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OrderWidget(int userId, QWidget *parent = 0);

signals:
    void orderItemClick(Model::OrderDetail);
    void showHomePage();
    void orderDetailUpdated(QList<Model::OrderDetail> orderDetails);

public slots:
    void updateQMLCart();
    void addItemToCart(Model::OrderDetail);
    void updateItemInCart(Model::OrderDetail);
    void removeItemFromCart(Model::OrderDetail);
    void applyOrderClicked();
    void cancelOrderClicked();
    void addDiscountClicked();
    void orderItemClick(QString);

private:
    void initOrderList();
    void initOrderCommand();
    void clearShoppingCart();
    void updateLCDTotalCash();
    void applyOrder();

    Model::OrderDetail getOrderByIndexId(QString indexId);

    int m_userId;
    QVBoxLayout* layout;
    QDeclarativeView* m_declarativeView;
    QLCDNumber* m_totalCashLCD;
    QLCDNumber* m_discountLCD;

    Model::CartOrder m_cartOrder;
};


#endif // ORDERWIDGET_H
