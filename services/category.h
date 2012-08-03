#ifndef SERVICES_CATEGORY_H
#define SERVICES_CATEGORY_H

#include <QList>
#include "model/category.h"

namespace Services {

class Category
{
public:
    static Model::Category getById(int id);
    static QList<Model::Category> getAll();
};


}
#endif // SERVICES_CATEGORY_H
