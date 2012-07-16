#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QtSql>
#include <QString>
#include <vector>

#include "model/category.h"
#include "model/item.h"
#include "model/component.h"
#include "model/itemdetail.h"

using namespace Model;

namespace Database
{
    class DatabaseManager
    {
    public:
        DatabaseManager();
        ~DatabaseManager();
        std::vector<Category> getCategories();
        std::vector<Item> getItemsInCategory(int categoryId);
        std::vector<ItemDetail> getItemDetails(int itemId);
        std::vector<Component> getAllCompnents();
        std::vector<Component> getCompnentsInItem(int itemId);
        Component getComponentById(int componentId);

    private:
        QSqlDatabase database;
    };
}

#endif // DATABASEMANAGER_H
