#ifndef SERVICES_EVENT_H
#define SERVICES_EVENT_H

#include "MangoService_global.h"
#include "../MangoModel/event.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT Event
{
public:
    static bool add(Model::Event event);
    static QList<Model::Event> getAll();
    static QList<Model::Event> getBetweenDateTime(QDateTime from, QDateTime to);
};

}

#endif // SERVICES_EVENT_H
