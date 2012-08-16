#ifndef DATABASE_SUGAR_H
#define DATABASE_SUGAR_H

#include <QList>
#include "MangoDatabase_global.h"
#include "../MangoModel/sugar.h"

namespace Database {

class MANGODATABASESHARED_EXPORT Sugar
{
public:
    static Model::Sugar getById(int id);
    static QList<Model::Sugar> getAll();
};

}

#endif // DATABASE_SUGAR_H
