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
        WithoutSugar = 1,
        LessSugar,
        NormalSugar,
        MoreSugar
    };

    Sugar(int id);
    Sugar(int id, const QString& arabicName, const QString& englishName);

};

}

#endif // MODEL_SUGAR_H
