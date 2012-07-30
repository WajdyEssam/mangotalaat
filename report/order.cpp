#include "order.h"

Order::Order(int id, QDateTime orderDate, int orderType, int cash, int discount, int totalCash, int isCancelled)
{
    this->m_id = id;
    this->m_orderDate = orderDate;
    this->m_orderType = orderType;
    this->m_cash = cash;
    this->m_discount = discount;
    this->m_totalCash = totalCash;
    this->m_isCancelled = isCancelled;
}
