#ifndef DATABASE_SIZE_H
#define DATABASE_SIZE_H

#include <QList>
#include "MangoDatabase_global.h"
#include "../MangoModel/size.h"

namespace Database {

class MANGODATABASESHARED_EXPORT Size
{
public:
    static Model::Size getById(int id);
    static QList<Model::Size> getAll();
};

}

#endif // DATABASE_SIZE_H
