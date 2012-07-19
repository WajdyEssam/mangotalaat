#ifndef ITEMDETAIL_H
#define ITEMDETAIL_H

namespace Model {
    class ItemDetail
    {
    public:
        ItemDetail(int aId, int aItemId, int aSizeId, int aPrice);

        int getId() const { return this->id; }
        int getItemId() const { return this->itemId; }
        int getSizeId() const { return this->sizeId ;}
        int getPrice() const { return this->price; }

    private:
        int id;
        int itemId;
        int sizeId;
        int price;
    };
}

#endif // ITEMDETAIL_H
