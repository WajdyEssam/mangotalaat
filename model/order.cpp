#include "order.h"

namespace Model {

Order::Order(int id) :
    m_id(id)
{}

Order::Order(int id, QDateTime createdDateTime, OrderType orderType, int cash, int discount, int totalCash, int isCancelled) :
    m_id(id), m_createdDateTime(createdDateTime), m_orderType(orderType), m_cash(cash), m_discount(discount), m_totalCash(totalCash), m_isCancelled(isCancelled)
{}

void Order::setOrderType(OrderType orderType)
{
    m_orderType = orderType;
}

void Order::setIsCancelled(bool isCancelled)
{
    m_isCancelled = isCancelled;
}

int Order::id() const
{
    return this->m_id;
}

QDateTime Order::createdDateTime() const
{
    return this->m_createdDateTime;
}

OrderType Order::orderType() const
{
    return this->m_orderType;
}

int Order::cash() const
{
    return this->m_cash;
}

int Order::discount() const
{
    return this->m_discount;
}

int Order::totalCash() const
{
    return this->m_totalCash;
}

int Order::isCancelled() const
{
    return this->m_isCancelled;
}

}
