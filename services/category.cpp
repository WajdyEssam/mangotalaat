#include "category.h"
#include "database/category.h"

namespace Services {

Model::Category Category::getById(int id)
{
    return Database::Category::getById(id);
}

QList<Model::Category> Category::getAll()
{
    return Database::Category::getAll();
}

}
