#ifndef DATABASE_CATEGORY_H
#define DATABASE_CATEGORY_H

#include <QList>
#include "model/category.h"

namespace Database {

class Category
{
public:
    static Model::Category getById(int id);
    static QList<Model::Category> getAll();
};

}

#endif // DATABASE_CATEGORY_H
