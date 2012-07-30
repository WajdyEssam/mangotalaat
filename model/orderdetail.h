#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include <QStringList>
#include "constants.h"

namespace Model {
    class OrderDetail
    {
    public:
        OrderDetail() {}
        OrderDetail(int aItemDetaildId);
        OrderDetail(int aItemDetailId, int aQuantity, QStringList aComponentsIds, QStringList aAdditionalsIds,
            SUGAR aSugar, QString aOrderIndexId);

        int getItemDetialId() const { return this->itemDetailId; }
        int getQunatity()const { return this->quantity; }
        QStringList getComponentsIds() const { return this->componentsIds; }
        QStringList getAdditionalsIds() const { return this->additionalsIds; }
        SUGAR getSugar() const { return this->sugar; }
        int getCash() const { return this->cash; }
        QString getSizeDescription() {return this->sizeDescription;}
        QString getArabicName() {return this->arabicName;}
        int getCategoryId() {return this->categoryId;}
        QString getOrderIndexId() const { return this->orderIndexId; }

    private:
        void fillOtherInformation();
        QString getTimeStamp();

        QString orderIndexId;
        int itemDetailId;
        int quantity;
        QStringList componentsIds;
        QStringList additionalsIds;
        SUGAR sugar;
        int cash;
        QString sizeDescription;
        int categoryId;
        QString arabicName;
    };
}
#endif // ORDER_H
