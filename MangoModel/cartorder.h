#ifndef MODEL_CARTORDER_H
#define MODEL_CARTORDER_H

#include <QObject>
#include "MangoModel_global.h"
#include "orderdetail.h"
#include "ordertype.h"

namespace Model
{

class MANGOMODELSHARED_EXPORT CartOrder : public QObject
{
    Q_OBJECT

public:
    CartOrder();
    void add(Model::OrderDetail orderDetail);
    void update(Model::OrderDetail orderDetail);
    void remove(Model::OrderDetail orderDetail);
    void clear();

    void setDiscount(int discount);
    int discount() const;

    void setOrderType(Model::OrderType::OrderTypes orderType);
    Model::OrderType::OrderTypes orderType() const;

    int totalCashBeforeDiscount() const;
    int totalCashAfterDiscount() const;
    bool isEmpty() const;

    QList<Model::OrderDetail> orderDetails() const;
    Model::OrderDetail getOrderByIndexId(QString indexId);

signals:
    void cartOrderUpdated();

private:
    int m_discount;
    QList<Model::OrderDetail> m_orderDetails;
    Model::OrderType::OrderTypes m_orderType;

};

}

#endif // MODEL_CARTORDER_H
