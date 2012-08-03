#include "event.h"
#include "database/event.h"
#include "services/user.h"

namespace Services {

bool Event::add(Model::Event event)
{
    return Database::Event::add(event);
}

QList<Model::Event> Event::getAll()
{
    QList<Model::Event> events = Database::Event::getAll();
    for (QList<Model::Event>::iterator i = events.begin(); i != events.end(); ++i) {
        i->setUser(Services::User::getById(i->user().id()));
    }

    return events;
}

QList<Model::Event> Event::getBetweenDateTime(QDateTime from, QDateTime to)
{
    QList<Model::Event> events = Database::Event::getBetweenDateTime(from, to);
    for (QList<Model::Event>::iterator i = events.begin(); i != events.end(); ++i) {
        i->setUser(Services::User::getById(i->user().id()));
    }

    return events;
}

}
