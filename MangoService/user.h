#ifndef SERVICES_USER_H
#define SERVICES_USER_H

#include "MangoService_global.h"
#include "../MangoModel/user.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT User
{
public:
    static Model::User getById(int id);
    static QList<Model::User> getAll();
};


}
#endif // SERVICES_USER_H
