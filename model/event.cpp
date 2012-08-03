#include "event.h"

namespace Model {

Event::Event() :
    m_id(-1)
{}

Event::Event(int id) :
    m_id(id)
{}

Event::Event(int id, Model::User user, QDateTime createDateTime, EventTypes eventType) :
    m_id(id), m_user(user), m_createdDateTime(createDateTime), m_eventType(eventType)
{}

int Event::id() const
{
    return m_id;
}

Model::User Event::user() const
{
    return m_user;
}

QDateTime Event::createdDateTime() const
{
    return m_createdDateTime;
}

Event::EventTypes Event::eventType()
{
    return m_eventType;
}

void Event::setUser(User user)
{
    m_user = user;
}

void Event::setCreatedDateTime(QDateTime createDateTime)
{
    m_createdDateTime = createDateTime;
}

void Event::setEventType(Event::EventTypes eventTypes)
{
    m_eventType = eventTypes;
}

}
