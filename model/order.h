#ifndef ORDERREPORT_H
#define ORDERREPORT_H

#include <QDateTime>
#include <QString>
#include "constants.h"

class Order
{
public:
    Order(int id, QDateTime orderDate, ORDER_TYPE orderType, int cash, int discount, int totalCash, int isCancelled);

    int getId() const { return this->m_id ;}
    QDateTime getOrderDate() const { return this->m_orderDate; }
    ORDER_TYPE getOrderType() const { return this->m_orderType; }
    int getCash() const { return this->m_cash; }
    int getDiscount() const { return this->m_discount; }
    int getTotalCash() const { return this->m_totalCash; }
    int isCancelled() const { return this->m_isCancelled; }

private:
    int m_id;
    QDateTime m_orderDate;
    ORDER_TYPE m_orderType;
    int m_cash;
    int m_discount;
    int m_totalCash;
    bool m_isCancelled;
};

#endif // ORDERREPORT_H
