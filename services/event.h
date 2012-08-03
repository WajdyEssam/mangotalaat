#ifndef SERVICES_EVENT_H
#define SERVICES_EVENT_H

#include "model/event.h"

namespace Services {

class Event
{
public:
    static bool add(Model::Event event);
    static QList<Model::Event> getAll();
    static QList<Model::Event> getBetweenDateTime(QDateTime from, QDateTime to);
};

}

#endif // SERVICES_EVENT_H
