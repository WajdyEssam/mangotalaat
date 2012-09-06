#include "cartorder.h"

namespace Model {

CartOrder::CartOrder() : m_discount(0), m_orderType(OrderType::CASH)
{}

void CartOrder::add(Model::OrderDetail orderDetail)
{
    m_orderDetails.append(orderDetail);
    emit cartOrderUpdated();
}

void CartOrder::update(Model::OrderDetail oldOrderDetail)
{
    for(int i=0; i<m_orderDetails.size(); i++) {
        Model::OrderDetail order = m_orderDetails.at(i);
        if ( order.orderIndexId() == oldOrderDetail.orderIndexId() ) {
            m_orderDetails.removeAt(i);
            break;
        }
    }

    m_orderDetails.append(oldOrderDetail);
    emit cartOrderUpdated();
}

void CartOrder::remove(Model::OrderDetail oldOrderDetail)
{
    for(int i=0; i<m_orderDetails.size(); i++) {
        Model::OrderDetail order = m_orderDetails.at(i);

        if ( order.orderIndexId() == oldOrderDetail.orderIndexId() ) {
            m_orderDetails.removeAt(i);
            break;
        }
    }

    emit cartOrderUpdated();
}

void CartOrder::clear()
{
    m_orderDetails.clear();
    m_discount = 0;
    m_orderType = OrderType::CASH;
    emit cartOrderUpdated();
}

void CartOrder::setDiscount(int discount)
{
    m_discount = discount;
    emit cartOrderUpdated();
}

int CartOrder::discount() const
{
    return m_discount;
}

int CartOrder::totalCashBeforeDiscount() const
{
    int cash = 0;
    foreach(Model::OrderDetail order, m_orderDetails) {
        cash += order.cash();
    }

    return cash;
}

int CartOrder::totalCashAfterDiscount() const
{
    return this->totalCashBeforeDiscount() - this->discount();
}

bool CartOrder::isEmpty() const
{
    return (m_orderDetails.count() < 1) ? true : false;
}

void CartOrder::setOrderType(OrderType::OrderTypes orderType)
{
    m_orderType = orderType;
}

OrderType::OrderTypes CartOrder::orderType() const
{
    return m_orderType;
}

QList<Model::OrderDetail> CartOrder::orderDetails() const
{
    return m_orderDetails;
}

Model::OrderDetail CartOrder::getOrderByIndexId(QString indexId) {
    foreach(Model::OrderDetail order, m_orderDetails) {
        if ( order.orderIndexId() == indexId )
            return order;
    }

    return m_orderDetails.at(0);
}


}
