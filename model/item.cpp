#include "item.h"

namespace Model
{
    Item::Item()
    {}

    Item::Item(int aId, const QString& aArabicName, const QString& aEnglishName, int aCategoryId, int aSizeId, int aPrice)
    {
        this->id = aId;
        this->arabicName = aArabicName;
        this->englishName = aEnglishName;
        this->categoryId = aCategoryId;
        this->sizeId = aSizeId;
        this->price = aPrice;
    }
}
