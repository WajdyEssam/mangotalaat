#ifndef MODEL_ORDER_H
#define MODEL_ORDER_H

#include <QDateTime>
#include <QString>
#include "MangoModel_global.h"
#include "ordertype.h"

namespace Model {

class MANGOMODELSHARED_EXPORT Order
{
public:
    Order(int id);
    Order(int id, QDateTime createdDateTime, OrderType orderType, int cash, int discount, int totalCash, int isCancelled);

    int id() const;
    QDateTime createdDateTime() const;
    OrderType orderType() const;
    int cash() const;
    int discount() const ;
    int totalCash() const ;
    int isCancelled() const;

    void setOrderType(OrderType orderType);
    void setIsCancelled(bool isCancelled);

private:
    int m_id;
    QDateTime m_createdDateTime;
    OrderType m_orderType;
    int m_cash;
    int m_discount;
    int m_totalCash;
    bool m_isCancelled;
};

}

#endif // MODEL_ORDER_H
