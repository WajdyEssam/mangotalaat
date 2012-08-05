#include "size.h"
#include "../MangoDatabase/size.h"

namespace Services {

Model::Size Size::getById(int id)
{
    return Database::Size::getById(id);
}

QList<Model::Size> Size::getAll()
{
    return Database::Size::getAll();
}

}
