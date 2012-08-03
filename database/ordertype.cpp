#include "ordertype.h"
#include "databasemanager.h"

namespace Database {

Model::OrderType OrderType::getById(int id)
{
    QList<Model::OrderType> ordersTypes;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from orders_type WHERE id = ?");
    query.addBindValue(id);

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();

        Model::OrderType orderType(id, arabicName, englishName);
        ordersTypes.append(orderType);
    }

    return ordersTypes.first();
}

QList<Model::OrderType> OrderType::getAll()
{
    QList<Model::OrderType> ordersTypes;

    DatabaseManager mgr;

    QSqlQuery query("SELECT * from orders_type");

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();

        Model::OrderType orderType(id, arabicName, englishName);
        ordersTypes.append(orderType);
    }

    return ordersTypes;
}

}
