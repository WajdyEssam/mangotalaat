#ifndef MODEL_EVENT_H
#define MODEL_EVENT_H

#include "user.h"

namespace Model {

class Event
{
public:
    enum  EventTypes {
        Login = 1,
        Logout = 2
    };

    Event();
    Event(int id);
    Event(int id, Model::User user, QDateTime createDateTime, EventTypes eventType);

    int id() const;
    Model::User user() const;
    QDateTime createdDateTime() const;
    EventTypes eventType();

    void setUser(Model::User user);
    void setCreatedDateTime(QDateTime createDateTime);
    void setEventType(EventTypes eventTypes);

private:
    int m_id;
    Model::User m_user;
    QDateTime m_createdDateTime;
    EventTypes m_eventType;
};

}

#endif // MODEL_EVENT_H
