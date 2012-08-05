#include "size.h"
#include "databasemanager.h"

namespace Database {

Model::Size Size::getById(int id)
{
    QList<Model::Size> sizes;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from item_size WHERE id = ?");
    query.addBindValue(id);
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();

        Model::Size size(id, arabicName, englishName);
        sizes.append(size);
    }

    return sizes.first();
}

QList<Model::Size> Size::getAll()
{
    QList<Model::Size> sizes;

    DatabaseManager mgr;

    QSqlQuery query("SELECT * from item_size");
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();

        Model::Size size(id, arabicName, englishName);
        sizes.append(size);
    }

    return sizes;
}

}
