#include "checkout.h"
#include "databasemanager.h"

namespace Database {

bool Checkout::add(Model::Checkout checkout)
{
    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("INSERT INTO system_checkout(checkout_time) VALUES(?)");
    query.addBindValue(checkout.createdDateTime());

    return query.exec();
}

Model::Checkout Checkout::getById(int id)
{
    QList<Model::Checkout> checkouts;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from system_checkout WHERE id = ?");
    query.addBindValue(id);

    while(query.next()) {
        int id = query.value(0).toInt();
        QDateTime createdDateTime = query.value(1).toDateTime();

        Model::Checkout checkout(id, createdDateTime);
        checkouts.append(checkout);
    }

    return additionals.first();
}

QList<Model::Checkout> Checkout::getAll()
{
    QList<Model::Checkout> checkouts;

    DatabaseManager mgr;
    QSqlQuery query("SELECT * from system_checkout");

    while(query.next()) {
        int id = query.value(0).toInt();
        QDateTime createdDateTime = query.value(1).toDateTime();

        Model::Checkout checkout(id, createdDateTime);
        checkouts.append(checkout);
    }

    return checkouts;
}


}
