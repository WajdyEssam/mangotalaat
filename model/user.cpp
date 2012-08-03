#include "user.h"

namespace Model {

User::User(int id) :
    m_id(id)
{}

User::User(int id, QString username, QString password, QDateTime registerTime) :
    m_(id), m_username(username), m_password(password), m_registerTime(registerTime)
{}

int User::id() const
{
    return this->m_id;
}

QString User::userName() const
{
    return this->m_username;
}

QString User::password() const
{
    return this->m_password;
}

QDateTime User::registerDateTime() const
{
    return this->m_registerTime;
}

}
