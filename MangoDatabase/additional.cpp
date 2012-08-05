#include "additional.h"
#include "databasemanager.h"

namespace Database {

Model::Additional Additional::getById(int id)
{
    QList<Model::Additional> additionals;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from additionals WHERE id = ?");
    query.addBindValue(id);
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();
        int price = query.value(3).toInt();

        Model::Additional additional(id, price, arabicName, englishName);
        additionals.append(additional);
    }

    return additionals.first();
}

QList<Model::Additional> Additional::getAll()
{
    QList<Model::Additional> additionals;

    DatabaseManager mgr;
    QSqlQuery query("SELECT * from additionals");
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();
        int price = query.value(3).toInt();

        Model::Additional additional(id, price, arabicName, englishName);
        additionals.append(additional);
    }

    return additionals;
}

}
