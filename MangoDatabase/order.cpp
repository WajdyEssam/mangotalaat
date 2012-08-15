#include <QSqlQuery>
#include "order.h"
#include "databasemanager.h"

namespace Database {

int Order::add(Model::Order order)
{
    DatabaseManager mgr;

    QSqlQuery query;

    query.prepare("INSERT INTO orders(order_time, order_type_id, cash, discount, total_cash, is_cancelled) VALUES(?,?,?,?,?,0)");
    query.addBindValue(order.createdDateTime());
    query.addBindValue(order.orderType().id());
    query.addBindValue(order.cash());
    query.addBindValue(order.discount());
    query.addBindValue(order.isCancelled());

    bool ok = query.exec();

    if (ok)
        return query.lastInsertId().toInt();
    else
        return -1;
}

bool Order::update(Model::Order order)
{
    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("UPDATE orders SET order_time = ?, order_type_id = ?, cash = ?, discount = ?, total_cash = ?, is_cancelled = ? WHERE id = ?");
    query.addBindValue(order.createdDateTime());
    query.addBindValue(order.orderType().id());
    query.addBindValue(order.cash());
    query.addBindValue(order.discount());
    query.addBindValue(order.totalCash());
    query.addBindValue(order.isCancelled());
    query.addBindValue(order.id());

    return query.exec();
}

Model::Order Order::getById(int order_id)
{
    QList<Model::Order> orders;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from orders WHERE id = ?");
    query.addBindValue(order_id);
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QDateTime orderDate = query.value(1).toDateTime();
        Model::OrderType orderType = Model::OrderType(query.value(2).toInt());
        int cash = query.value(3).toInt();
        int discount = query.value(4).toInt();
        int totalCash = query.value(5).toInt();
        int isCancelled = query.value(6).toInt();

        Model::Order order(id, orderDate, orderType, cash, discount, totalCash, isCancelled);
        orders.append(order);
    }

    return orders.first();
}

QList<Model::Order> Order::getAll()
{
    QList<Model::Order> orders;

    DatabaseManager mgr;

    QSqlQuery query("SELECT * from orders");
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QDateTime orderDate = query.value(1).toDateTime();
        Model::OrderType orderType = Model::OrderType(query.value(2).toInt());
        int cash = query.value(3).toInt();
        int discount = query.value(4).toInt();
        int totalCash = query.value(5).toInt();
        int isCancelled = query.value(6).toInt();

        Model::Order order(id, orderDate, orderType, cash, discount, totalCash, isCancelled);
        orders.append(order);
    }

    return orders;
}

QList<Model::Order> Order::getOrdersBetweenDateTime(QDateTime from, QDateTime to)
{
    QList<Model::Order> orders;

    DatabaseManager mgr;
    QSqlQuery query(QString("SELECT * FROM orders"));

    while(query.next()){
        int id = query.value(0).toInt();
        QDateTime orderDate = query.value(1).toDateTime();
        Model::OrderType orderType = Model::OrderType(query.value(2).toInt());
        int cash = query.value(3).toInt();
        int discount = query.value(4).toInt();
        int totalCash = query.value(5).toInt();
        int isCancelled = query.value(6).toInt();

        Model::Order order(id, orderDate, orderType, cash, discount, totalCash, isCancelled);

        if ( orderDate >= from && orderDate <= to)
            orders.append(order);
    }

    return orders;
}

QList<Model::Order> Order::getNotCancelledOrdersBetweenDateTime(QDateTime from, QDateTime to)
{
    QList<Model::Order> orders;

    DatabaseManager mgr;
    QSqlQuery query(QString("SELECT * FROM orders WHERE is_cancelled = 0"));

    while(query.next()){
        int id = query.value(0).toInt();
        QDateTime orderDate = query.value(1).toDateTime();
        Model::OrderType orderType = Model::OrderType(query.value(2).toInt());
        int cash = query.value(3).toInt();
        int discount = query.value(4).toInt();
        int totalCash = query.value(5).toInt();
        int isCancelled = query.value(6).toInt();

        Model::Order order(id, orderDate, orderType, cash, discount, totalCash, isCancelled);

        if ( orderDate >= from && orderDate <= to)
            orders.append(order);
    }

    return orders;
}
}
