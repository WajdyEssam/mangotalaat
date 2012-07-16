#include "category.h"

namespace Model
{
    Category::Category(int aId, const QString& aArabicName, const QString& aEnglishName)
    {
        this->id = aId;
        this->arabicName = aArabicName;
        this->englishName = aEnglishName;
    }
}
