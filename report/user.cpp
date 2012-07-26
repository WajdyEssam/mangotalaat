#include "user.h"

User::User(int id, QString username, QString password, QDateTime registerTime)
{
    this->m_id = id;
    this->m_username = username;
    this->m_password = password;
    this->m_registerTime = registerTime;
}
