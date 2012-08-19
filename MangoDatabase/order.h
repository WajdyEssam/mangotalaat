#ifndef DATABASE_ORDER_H
#define DATABASE_ORDER_H

#include <QList>
#include "MangoDatabase_global.h"
#include <QDateTime>

#include "../MangoModel/order.h"

namespace Database {

class MANGODATABASESHARED_EXPORT Order
{
public:
    static int add(Model::Order order);
    static bool update(Model::Order order);
    static Model::Order getById(int order_id);
    static QList<Model::Order> getAll();
    static QList<Model::Order> getByUserId(int userId);
    static QList<Model::Order> getOrdersBetweenDateTime(QDateTime from, QDateTime to);
    static QList<Model::Order> getNotCancelledOrdersBetweenDateTime(QDateTime from, QDateTime to);
};

}

#endif // DATABASE_ORDER_H
