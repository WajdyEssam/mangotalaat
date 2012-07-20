#ifndef ORDER_H
#define ORDER_H

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

    private:
        void computeCash();

    private:
        int itemDetailId;
        int quantity;
        QStringList componentsIds;
        QStringList additionalsIds;
        QString sugar;
        int cash;
    };
}
#endif // ORDER_H
