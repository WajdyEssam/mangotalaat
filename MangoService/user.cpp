#include "user.h"
#include "../MangoDatabase/user.h"

namespace Services {

bool User::add(Model::User user)
{
    if (getByUserName(user.userName()).id() != 0)
        return false;

    return Database::User::add(user);
}

bool User::update(Model::User user)
{
    return Database::User::update(user);
}

bool User::removeById(int id)
{
    return Database::User::removeById(id);
}

Model::User User::getById(int id)
{
    return Database::User::getById(id);
}

Model::User User::getByUserName(QString username)
{
    return Database::User::getByUserName(username);
}

QList<Model::User> User::getAll()
{
    return Database::User::getAll();
}


}
