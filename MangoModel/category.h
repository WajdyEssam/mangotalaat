#ifndef MODEL_CATEGORY_H
#define MODEL_CATEGORY_H

#include <QString>
#include "MangoModel_global.h"
#include "baseitem.h"

namespace Model
{

class MANGOMODELSHARED_EXPORT Category : public BaseItem
{
public:
    enum Categories {
        Fresh_JUICES = 1,
        Cocktails,
        Special_Dishes,
        Speical_Cocktial,
        Red_Bull,
        Frozen_Yogurt,
        Ice_Cream,
        Milk_Shake
    };

    Category(int id);
    Category(int id, const QString& arabicName, const QString& englishName);

};

}

#endif // MODEL_CATEGORY_H
