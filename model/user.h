#ifndef USER_H
#define USER_H

#include <QString>
#include <QDateTime>

class User
{
public:
    User() { }

    User(int id, QString username, QString password, QDateTime registerTime);

    int getId() const { return this->m_id; }
    QString getUsername() const { return this->m_username; }
    QString getPassword() const { return this->m_password; }
    QDateTime getRegisterTime() const { return this->m_registerTime; }

private:
    int m_id;
    QString m_username;
    QString m_password;
    QDateTime m_registerTime;
};

#endif // USER_H
