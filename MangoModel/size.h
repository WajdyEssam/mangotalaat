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

    Size(int id);
    Size(int id, const QString& arabicName, const QString& englishName);
};

}

#endif // MODEL_SIZE_H
