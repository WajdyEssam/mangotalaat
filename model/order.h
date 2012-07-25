#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include <QStringList>

namespace Model {
    class Order
    {

    public:
        Order() {}
        Order(int aItemDetaildId);
        Order(int aItemDetailId, int aQuantity, QStringList aComponentsIds, QStringList aAdditionalsIds);

        int getItemDetialId() const { return this->itemDetailId; }
        int getQunatity()const { return this->quantity; }
        QStringList getComponentsIds() const { return this->componentsIds; }
        QStringList getAdditionalsIds() const { return this->additionalsIds; }
        QString getSugar() const { return this->sugar; }
        int getCash() const { return this->cash; }

        QString getSizeDescription() {return this->sizeDescription;}
        QString getArabicName() {return this->arabicName;}
        int getCategoryId() {return this->categoryId;}

    private:
        void fillOtherInformation();

    private:
        int itemDetailId;
        int quantity;
        QStringList componentsIds;
        QStringList additionalsIds;
        QString sugar;
        int cash;

    private:
        QString sizeDescription;
        int categoryId;
        QString arabicName;
    };
}
#endif // ORDER_H
