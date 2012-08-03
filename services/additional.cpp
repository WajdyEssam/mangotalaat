#include "additional.h"
#include "database/additional.h"

namespace Services {

Model::Additional Additional::getById(int id)
{
    return Database::Additional::getById(id);
}

QList<Model::Additional> Additional::getAll()
{
    return Database::Additional::getAll();
}


}
