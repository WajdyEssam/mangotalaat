#ifndef DATABASE_COMPONENT_H
#define DATABASE_COMPONENT_H

#include <QList>
#include "model/component.h"

namespace Database {

class Component
{
public:
    static Model::Component getById(int id);
    static QList<Model::Component> getAll();
};

}

#endif // DATABASE_COMPONENT_H
