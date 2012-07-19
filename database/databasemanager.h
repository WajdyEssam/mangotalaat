#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql/QtSql>
#include <QString>
#include <vector>

#include "model/category.h"
#include "model/item.h"
#include "model/component.h"
#include "model/itemdetail.h"
#include "model/additionals.h"

using namespace Model;

namespace Database
{
    class DatabaseManager
    {
    public:
        DatabaseManager();
        ~DatabaseManager();

        std::vector<Item> getItemsInCategory(int categoryId);
        std::vector<Component> getCompnentsInItem(int itemId);
        std::vector<ItemDetail> getItemDetails(int itemId);

        std::vector<Category> getCategories();
        std::vector<Component> getAllCompnents();
        std::vector<Additionals> getAllAdditionals();

        ItemDetail getItemDetailById(int itemDetialId);
        Item getItemById(int itemId);
        Component getComponentById(int componentId);

        enum LAGNUAGE { ARABIC, ENGLISH };
        QString getItemSizeDescription(int sizeId, LAGNUAGE language);

    private:
        QSqlDatabase database;
    };
}

#endif // DATABASEMANAGER_H
