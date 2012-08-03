#ifndef DATABASE_USER_H
#define DATABASE_USER_H

#include <QList>
#include "model/user.h"

namespace Database {

class User
{
public:
    static Model::User getById(int id);
    static QList<Model::User> getAll();
};

}

#endif // DATABASE_USER_H
