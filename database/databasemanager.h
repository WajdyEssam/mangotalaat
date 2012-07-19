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
        std::vector<Category> getCategories();
        std::vector<Item> getItemsInCategory(int categoryId);
        std::vector<ItemDetail> getItemDetails(int itemId);
        ItemDetail getItemDetailById(int itemDetialId);
        std::vector<Component> getAllCompnents();
        std::vector<Component> getCompnentsInItem(int itemId);
        std::vector<Additionals> getAllAdditionals();
        Component getComponentById(int componentId);

        enum LAGNUAGE { ARABIC, ENGLISH };
        QString getItemSizeDescription(int sizeId, LAGNUAGE language);

    private:
        QSqlDatabase database;
    };
}

#endif // DATABASEMANAGER_H
