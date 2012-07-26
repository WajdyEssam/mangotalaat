#ifndef LOGINREPORT_H
#define LOGINREPORT_H

#include "user.h"

class LoginReport
{
public:
    LoginReport(int id, User user, QDateTime eventTime, int eventType);

    int getId() const { return this->m_id; }
    User getUser() const { return this->m_user; }
    QDateTime getEventTime() const { return this->m_eventTime; }
    int getEventType() const { return this->m_eventType; }

private:
    int m_id;
    User m_user;
    QDateTime m_eventTime;
    int m_eventType;
};

#endif // LOGINREPORT_H
