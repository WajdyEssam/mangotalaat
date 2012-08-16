#ifndef MODEL_SUGAR_H
#define MODEL_SUGAR_H

#include <QString>
#include "MangoModel_global.h"
#include "baseitem.h"

namespace Model
{

class MANGOMODELSHARED_EXPORT Sugar : public BaseItem
{
public:
    enum Sugars {
        WithoutSugar = 0,
        LessSugar = 1,
        NormalSugar = 2,
        MoreSugar = 3
    };

    Sugar(int id);
    Sugar(int id, const QString& arabicName, const QString& englishName);

};

}

#endif // MODEL_SUGAR_H
