#include "item.h"
#include "databasemanager.h"

namespace Database {

Model::Item Item::getById(int id)
{
    QList<Model::Item> items;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from items WHERE id = ?");
    query.addBindValue(id);
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabic_name = query.value(1).toString();
        QString english_name = query.value(2).toString();
        int categories_id= query.value(3).toInt();

        Model::Item item(id, Model::Category(categories_id), arabic_name, english_name);
        items.append(item);
    }

    return items.first();
}

QList<Model::Item> Item::getByCategoryId(int categoryId)
{
    QList<Model::Item> items;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from items WHERE categories_id = ?");
    query.addBindValue(categoryId);
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabic_name = query.value(1).toString();
        QString english_name = query.value(2).toString();
        int categories_id= query.value(3).toInt();

        Model::Item item(id, Model::Category(categories_id), arabic_name, english_name);
        items.append(item);
    }

    return items;
}

QList<Model::Item> Item::getAll()
{
    QList<Model::Item> items;

    DatabaseManager mgr;

    QSqlQuery query("SELECT * from items");
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabic_name = query.value(1).toString();
        QString english_name = query.value(2).toString();
        int categories_id= query.value(3).toInt();

        Model::Item item(id, Model::Category(categories_id), arabic_name, english_name);
        items.append(item);
    }

    return items;
}

}
