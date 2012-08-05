#ifndef DATABASE_USER_H
#define DATABASE_USER_H

#include <QList>
#include "MangoDatabase_global.h"
#include "../MangoModel/user.h"

namespace Database {

class MANGODATABASESHARED_EXPORT User
{
public:
    static Model::User getById(int id);
    static QList<Model::User> getAll();
};

}

#endif // DATABASE_USER_H
