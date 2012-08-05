#ifndef DATABASE_COMPONENT_H
#define DATABASE_COMPONENT_H

#include <QList>
#include "MangoDatabase_global.h"
#include "../MangoModel/component.h"

namespace Database {

class MANGODATABASESHARED_EXPORT Component
{
public:
    static Model::Component getById(int id);
    static QList<Model::Component> getAll();
};

}

#endif // DATABASE_COMPONENT_H
