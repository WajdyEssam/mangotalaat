#ifndef SERVICES_SUGAR_H
#define SERVICES_SUGAR_H

#include <QList>
#include "MangoService_global.h"
#include "../MangoModel/sugar.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT Sugar
{
public:
    static Model::Sugar getById(int id);
    static QList<Model::Sugar> getAll();
};


}
#endif // SERVICES_SUGAR_H
