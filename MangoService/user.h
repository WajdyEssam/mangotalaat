#ifndef SERVICES_USER_H
#define SERVICES_USER_H

#include "MangoService_global.h"
#include "../MangoModel/user.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT User
{
public:
    static bool add(Model::User user);
    static bool update(Model::User user);
    static bool removeById(int id);
    static Model::User getById(int id);
    static Model::User getByUserName(QString username);
    static QList<Model::User> getAll();
};


}
#endif // SERVICES_USER_H
