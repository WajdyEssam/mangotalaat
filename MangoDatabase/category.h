#ifndef DATABASE_CATEGORY_H
#define DATABASE_CATEGORY_H

#include <QList>
#include "MangoDatabase_global.h"
#include "../MangoModel/category.h"

namespace Database {

class MANGODATABASESHARED_EXPORT Category
{
public:
    static Model::Category getById(int id);
    static QList<Model::Category> getAll();
};

}

#endif // DATABASE_CATEGORY_H
