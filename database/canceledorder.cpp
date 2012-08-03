#include "canceledorder.h"
#include "databasemanager.h"

namespace Database {


bool CanceledOrder::add(Model::CanceledOrder canceledOrder)
{
    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("INSERT INTO order_canceled(order_id, cancel_time) VALUES(?,?)");
    query.addBindValue(canceledOrder.order().id());
    query.addBindValue(QDateTime::currentDateTime());

    return query.exec();
}

Model::CanceledOrder CanceledOrder::getById(int id)
{
    QList<Model::CanceledOrder> canceledOrders;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from order_canceled WHERE id = ?");
    query.addBindValue(id);

    while(query.next()) {
        int id = query.value(0).toInt();
        int order_id = query.value(1).toInt();
        QDateTime cancel_time = query.value(2).toDateTime();

        Model::Order order(order_id);
        Model::CanceledOrder canceledOrder(id, order, cancel_time);

        canceledOrders.append(canceledOrder);
    }

    return canceledOrders.first();
}

QList<Model::CanceledOrder> CanceledOrder::getAll()
{
    QList<Model::CanceledOrder> canceledOrders;

    DatabaseManager mgr;
    QSqlQuery query("SELECT * from order_canceled");

    while(query.next()) {
        int id = query.value(0).toInt();
        int order_id = query.value(1).toInt();
        QDateTime cancel_time = query.value(2).toDateTime();

        Model::Order order(order_id);
        Model::CanceledOrder canceledOrder(id, order, cancel_time);

        canceledOrders.append(canceledOrder);
    }

    return canceledOrders;
}


}
