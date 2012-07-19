#include "additionals.h"

namespace Model
{
    Additionals::Additionals(int aId, const QString& aArabicName, const QString& aEnglishName, int aPrice)
    {
        this->id = aId;
        this->arabicName = aArabicName;
        this->englishName = aEnglishName;
        this->price = aPrice;
    }
}
