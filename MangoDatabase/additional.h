#ifndef DATABASE_ADDITIONAL_H
#define DATABASE_ADDITIONAL_H

#include <QList>
#include "MangoDatabase_global.h"
#include "../MangoModel/additional.h"

namespace Database {

class MANGODATABASESHARED_EXPORT Additional
{
public:
    static Model::Additional getById(int id);
    static QList<Model::Additional> getAll();
};

}

#endif // DATABASE_ADDITIONAL_H
