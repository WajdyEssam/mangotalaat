#include "itemcomponent.h"
#include "databasemanager.h"

namespace Database {

QList<Model::ItemComponent> ItemComponent::getByItemId(int itemId)
{
    QList<Model::ItemComponent> itemComponents;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from item_components WHERE item_id = ?");
    query.addBindValue(itemId);
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        int item_id = query.value(1).toInt();
        int component_id = query.value(2).toInt();

        Model::Item item(item_id);
        Model::Component component(component_id);
        Model::ItemComponent itemComponent(id, item, component);

        itemComponents.append(itemComponent);
    }

    return itemComponents;
}

Model::ItemComponent ItemComponent::getById(int id)
{
    QList<Model::ItemComponent> itemComponents;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * from item_components WHERE id = ?");
    query.addBindValue(id);
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        int item_id = query.value(1).toInt();
        int component_id = query.value(2).toInt();

        Model::Item item(item_id);
        Model::Component component(component_id);
        Model::ItemComponent itemComponent(id, item, component);

        itemComponents.append(itemComponent);
    }

    return itemComponents.first();
}

}
