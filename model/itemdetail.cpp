#include "itemdetail.h"

namespace Model {
    ItemDetail::ItemDetail(int aId, int aItemId, int aSizeId, int aPrice)
    {
        this->id = aId;
        this->itemId = aItemId;
        this->sizeId = aSizeId;
        this->price = aPrice;
    }
}
