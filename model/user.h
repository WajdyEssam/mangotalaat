#ifndef MODEL_USER_H
#define MODEL_USER_H

#include <QString>
#include <QDateTime>

namespace Model {

class User
{
public:
    User(int id);
    User(int id, QString username, QString password, QDateTime registerTime);

    int id() const;
    QString userName() const;
    QString password() const;
    QDateTime registerDateTime() const;

private:
    int m_id;
    QString m_username;
    QString m_password;
    QDateTime m_registerTime;
};

}

#endif // MODEL_USER_H
