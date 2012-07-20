#include "order.h"
#include "database/databasemanager.h"
#include "model/itemdetail.h"

namespace Model {
    Order::Order(int aItemDetaildId) {
        this->itemDetailId = aItemDetaildId;
        this->quantity = 1;
        this->computeCash();
    }

    Order::Order(int aItemDetailId, int aQuantity, QStringList aComponentsIds, QStringList aAdditionalsIds) {
        this->itemDetailId = aItemDetailId;
        this->quantity = aQuantity;
        this->componentsIds = aComponentsIds;
        this->additionalsIds = aAdditionalsIds;
        this->computeCash();
    }

    void Order::computeCash() {
        Database::DatabaseManager database;
        Model::ItemDetail itemDetail = database.getItemDetailById(this->itemDetailId);
        this->cash = itemDetail.getPrice() * this->quantity;
    }
}
