#ifndef SERVICES_USER_H
#define SERVICES_USER_H

#include "model/user.h"

namespace Services {

class User
{
public:
    static Model::User getById(int id);
    static QList<Model::User> getAll();
};


}
#endif // SERVICES_USER_H
