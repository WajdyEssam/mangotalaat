#include "databasemanager.h"

namespace Database
{
    DatabaseManager::DatabaseManager()
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("mango.db");
        database.open();
    }

    DatabaseManager::~DatabaseManager()
    {
        database.close();
    }

    std::vector<Category> DatabaseManager::getCategories()
    {
        std::vector<Category> categories;

        QSqlQuery query("SELECT * FROM categories");
        while(query.next()) {
            int id = query.value(0).toInt();
            QString arabicName = query.value(1).toString();
            QString englishName = query.value(2).toString();

            Category category(id, arabicName, englishName);
            categories.push_back(category);
        }

        return categories;
    }

    std::vector<Item> DatabaseManager::getItemsInCategory(int categoryId)
    {
        std::vector<Item> items;
        QSqlQuery query(QString("SELECT * FROM items WHERE categories_id = %1").arg(categoryId));

        while(query.next()) {
            int id = query.value(0).toInt();
            QString arabicName = query.value(1).toString();
            QString englishName = query.value(2).toString();
            int categoryId = query.value(3).toInt();
            int sizeId = query.value(4).toInt();
            int price = query.value(5).toInt();

            Item item(id, arabicName, englishName, categoryId, sizeId, price);
            items.push_back(item);
        }

        return items;
    }

    Item DatabaseManager::getItemDetails(int itemId)
    {
        Item item;

        QSqlQuery query(QString("SELECT * FROM items WHERE id = %1").arg(itemId));
        while(query.next()) {
            int id = query.value(0).toInt();
            QString arabicName = query.value(1).toString();
            QString englishName = query.value(2).toString();
            int categoryId = query.value(3).toInt();
            int sizeId = query.value(4).toInt();
            int price = query.value(5).toInt();

            item = Item(id, arabicName, englishName, categoryId, sizeId, price);
        }

        return item;
    }

    std::vector<Component> DatabaseManager::getAllCompnents()
    {
        std::vector<Component> components;

        QSqlQuery query(QString("SELECT * FROM components"));
        while(query.next()){
            int id = query.value(0).toInt();
            QString arabicName = query.value(1).toString();
            QString englishName = query.value(2).toString();

            Component component(id, arabicName, englishName);
            components.push_back(component);
        }

        return components;
    }

    std::vector<Component> DatabaseManager::getCompnentsInItem(int itemId)
    {
        std::vector<Component> components;

        QSqlQuery query(QString("SELECT * FROM item_components WHERE item_id = %1").arg(itemId));
        while(query.next()){
            int componentId = query.value(2).toInt();
            components.push_back(getComponentById(componentId));
        }

        return components;
    }

    Component DatabaseManager::getComponentById(int componentId)
    {
        Component component;

        QSqlQuery query(QString("SELECT * FROM components WHERE id = %1").arg(componentId));
        while(query.next()) {
            int id = query.value(0).toInt();
            QString arabicName = query.value(1).toString();
            QString englishName = query.value(2).toString();

            component = Component(id, arabicName, englishName);
        }

        return component;
    }
}
