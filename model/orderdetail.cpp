#include "orderdetail.h"
#include "database/databasemanager.h"
#include "model/itemdetail.h"

namespace Model {

    OrderDetail::OrderDetail(int aItemDetaildId) {
        this->itemDetailId = aItemDetaildId;
        this->quantity = 1;
        this->orderIndexId = getTimeStamp();
        this->fillOtherInformation();
    }

    OrderDetail::OrderDetail(int aItemDetailId, int aQuantity, QStringList aComponentsIds, QStringList aAdditionalsIds,
                 SUGAR aSugar, QString aOrderIndexId) {
        this->itemDetailId = aItemDetailId;
        this->quantity = aQuantity;
        this->componentsIds = aComponentsIds;
        this->additionalsIds = aAdditionalsIds;
        this->sugar = aSugar;
        this->orderIndexId = aOrderIndexId;
        this->fillOtherInformation();
    }

    void OrderDetail::fillOtherInformation() {
        Database::DatabaseManager database;
        Model::ItemDetail itemDetail = database.getItemDetailById(this->itemDetailId);
        Model::Item item = database.getItemById(itemDetail.getItemId());

        // if item is special cocktail then the price will be the largest component price
        // this is just for mango and avocado
        int price = itemDetail.getPrice();
        int sizeId = itemDetail.getSizeId();

        this->sizeDescription = database.getItemSizeDescription(sizeId, Database::DatabaseManager::ARABIC);
        this->cash = price * this->quantity;
        this->categoryId = item.getCategoryId();
        this->arabicName = item.getArabicName();
    }

    QString OrderDetail::getTimeStamp() {
        return QString::number(QDateTime::currentMSecsSinceEpoch());
    }
}


