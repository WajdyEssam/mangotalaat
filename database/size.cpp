#include "size.h"
#include "databasemanager.h"

namespace Database {

Model::Size Size::getById(int id)
{
    QList<Size> sizes;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from item_size WHERE id = ?");
    query.addBindValue(id);

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();

        Model::Size size(id, arabicName, englishName);
        sizes.append(size);
    }

    return sizes.first();
}

QList<Size> Size::getAll()
{
    QList<Size> sizes;

    DatabaseManager mgr;

    QSqlQuery query("SELECT * from item_size");

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
