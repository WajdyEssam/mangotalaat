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
#include "model/order.h"

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

        Item getItemById(int itemId);
        ItemDetail getItemDetailById(int itemDetialId);
        Component getComponentById(int componentId);
        Additionals getAdditionalsById(int additionalsId);

        enum LAGNUAGE { ARABIC, ENGLISH };
        QString getItemSizeDescription(int sizeId, LAGNUAGE language);

        bool addOrder(QDateTime currentTime, int orderTypeId, int cash, int discount, int totalCash, QList<Model::Order> orders);
        bool cancelOrder(int orderId);

        bool closeTodayOrders(QDateTime time);
        bool addLoginEventLogging(int userId, QDateTime time, int eventType); // 1 login, 2 logout

    private:
        QString fromListToText(QStringList ids);
        QStringList fromTextToList(QString text);

    private:
        QSqlDatabase database;
    };
}

#endif // DATABASEMANAGER_H
