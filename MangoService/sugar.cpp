#include "sugar.h"
#include "../MangoDatabase/sugar.h"

namespace Services {

Model::Sugar Sugar::getById(int id)
{
    return Database::Sugar::getById(id);
}

QList<Model::Sugar> Sugar::getAll()
{
    return Database::Sugar::getAll();
}

}
