#include "component.h"

namespace Model
{
    Component::Component()
    {}

    Component::Component(int aId, const QString& aArabicName, const QString& aEnglishName)
    {
        this->id = aId;
        this->arabicName = aArabicName;
        this->englishName = aEnglishName;
    }
}
