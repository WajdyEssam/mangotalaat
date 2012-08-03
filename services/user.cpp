#include "user.h"
#include "database/user.h"

namespace Services {

Model::User User::getById(int id)
{
    return Database::User::getById(id);
}

QList<Model::User> User::getAll()
{
    return Database::User::getAll();
}


}
