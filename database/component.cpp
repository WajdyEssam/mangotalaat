#include "component.h"
#include "databasemanager.h"

namespace Database {

Model::Component Component::getById(int id)
{
    QList<Model::Component> components;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from components WHERE id = ?");
    query.addBindValue(id);

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();

        Model::Component component(id, arabicName, englishName);
        components.append(component);
    }

    return components.first();
}

QList<Component> Component::getAll()
{
    QList<Model::Component> components;

    DatabaseManager mgr;
    QSqlQuery query("SELECT * from components");

    while(query.next()) {
        int id = query.value(0).toInt();
        QString arabicName = query.value(1).toString();
        QString englishName = query.value(2).toString();

        Model::Component component(id, arabicName, englishName);
        components.append(component);
    }

    return components;
}

}
