#include "sugar.h"
#include "databasemanager.h"

namespace Database {

Model::Sugar Sugar::getById(int id)
{
    QList<Model::Sugar> sugars;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from sugars WHERE id = ?");
    query.addBindValue(id);
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();

        Model::Sugar sugar(id, arabicName, englishName);
        sugars.append(sugar);
    }

    return sugars.first();
}

QList<Model::Sugar> Sugar::getAll()
{
    QList<Model::Sugar> sugars;

    DatabaseManager mgr;
    QSqlQuery query("SELECT * from sugars");
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();

        Model::Sugar sugar(id, arabicName, englishName);
        sugars.append(sugar);
    }

    return sugars;
}

}
