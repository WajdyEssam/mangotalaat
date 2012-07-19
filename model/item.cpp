#include "item.h"

namespace Model
{
    Item::Item()
    {}

    Item::Item(int aId, const QString& aArabicName, const QString& aEnglishName, int aCategoryId)
    {
        this->id = aId;
        this->arabicName = aArabicName;
        this->englishName = aEnglishName;
        this->categoryId = aCategoryId;
    }
}
