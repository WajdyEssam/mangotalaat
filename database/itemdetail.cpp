#include "itemdetail.h"
#include "databasemanager.h"

namespace Database {

ItemDetail ItemDetail::getById(int id)
{
    QList<Model::ItemDetail> itemDetails;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * FROM item_details WHERE id = ?");
    query.addBindValue(itemId);

    while(query.next()) {
        int id = query.value(0).toInt();
        int item_id = query.value(1).toInt();
        int size_id = query.value(2).toInt();
        int price = query.value(3).toInt();

        Model::Item item(item_id);
        Model::Size size(size_id);
        Model::ItemDetail itemDetail = Model::ItemDetail(id, item, size, price);

        itemDetails.append(itemDetail);
    }

    return itemDetails.first();
}

QList<Model::ItemDetail> ItemDetail::getByItemId(int itemId)
{
    QList<Model::ItemDetail> itemDetails;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * FROM item_details WHERE item_id = ?");
    query.addBindValue(itemId);

    while(query.next()) {
        int id = query.value(0).toInt();
        int item_id = query.value(1).toInt();
        int size_id = query.value(2).toInt();
        int price = query.value(3).toInt();

        Model::Item item(item_id);
        Model::Size size(size_id);
        Model::ItemDetail itemDetail = Model::ItemDetail(id, item, size, price);

        itemDetails.append(itemDetail);
    }

    return itemDetails;
}


}
