#include "category.h"
#include "databasemanager.h"

namespace Database {

Model::Category Category::getById(int id)
{
    QList<Model::Category> categories;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from categories WHERE id = ?");
    query.addBindValue(id);

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();

        Model::Category category(id, arabicName, englishName);
        categories.append(category);
    }

    return categories.first();
}

QList<Model::Category> Category::getAll()
{
    QList<Model::Category> categories;

    DatabaseManager mgr;
    QSqlQuery query("SELECT * from categories");

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();

        Model::Category category(id, arabicName, englishName);
        categories.append(category);
    }

    return categories;
}

}
