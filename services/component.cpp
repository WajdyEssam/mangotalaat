#include "component.h"
#include "database/component.h"

namespace Services {

Model::Component Component::getById(int id)
{
    return Database::Component::getById(id);
}

QList<Model::Component> Component::getAll()
{
    return Database::Component::getAll();
}

}
