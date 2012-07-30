#ifndef LOGINREPORT_H
#define LOGINREPORT_H

#include "user.h"
#include "constants.h"

class Login
{
public:
    Login(int id, User user, QDateTime eventTime, LOGIN_TYPE eventType);

    int getId() const { return this->m_id; }
    User getUser() const { return this->m_user; }
    QDateTime getEventTime() const { return this->m_eventTime; }
    LOGIN_TYPE getEventType() const { return this->m_eventType; }

private:
    int m_id;
    User m_user;
    QDateTime m_eventTime;
    LOGIN_TYPE m_eventType;
};

#endif // LOGINREPORT_H
