#include "additional.h"
#include "../MangoDatabase/additional.h"

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
