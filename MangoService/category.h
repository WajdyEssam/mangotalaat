#ifndef SERVICES_CATEGORY_H
#define SERVICES_CATEGORY_H

#include <QList>
#include "MangoService_global.h"
#include "../MangoModel/category.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT Category
{
public:
    static Model::Category getById(int id);
    static QList<Model::Category> getAll();
};


}
#endif // SERVICES_CATEGORY_H
