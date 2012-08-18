#ifndef MODEL_SIZE_H
#define MODEL_SIZE_H

#include <QString>
#include "MangoModel_global.h"
#include "baseitem.h"

namespace Model
{

class MANGOMODELSHARED_EXPORT Size : public BaseItem
{
public:
    enum Sizes {
        SMALL=1,
        MEDIUM,
        LARGE,
        JAMBO,
        DISH,
        GALLON_1_HALF_L,
        GALLON_5L,
        GALLON_1L,
        NORMAL,
        FRUITS,
        BERRIES
    };

    Size(int id);
    Size(int id, const QString& arabicName, const QString& englishName);
};

}

#endif // MODEL_SIZE_H
