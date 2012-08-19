#include "user.h"
#include "databasemanager.h"

namespace Database {

bool User::add(Model::User user)
{
    DatabaseManager mgr;

    QSqlQuery query;

    query.prepare("INSERT INTO users(username, password, register_time) VALUES(?,?,?)");
    query.addBindValue(user.userName());
    query.addBindValue(user.password());
    query.addBindValue(user.registerDateTime());

    return query.exec();
}

bool User::update(Model::User user)
{
    DatabaseManager mgr;

    QSqlQuery query;

    query.prepare("UPDATE users SET username = ?, password = ? WHERE id = ?");
    query.addBindValue(user.userName());
    query.addBindValue(user.password());
    query.addBindValue(user.id());

    return query.exec();
}

bool User::removeById(int id)
{
    DatabaseManager mgr;

    QSqlQuery query;

    query.prepare("DELETE FROM users WHERE id = ?");
    query.addBindValue(id);

    return query.exec();
}

Model::User User::getById(int id)
{
    QList<Model::User> users ;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * FROM users WHERE id = ?");
    query.addBindValue(id);
    query.exec();

    while(query.next()){
        int id = query.value(0).toInt();
        QString username = query.value(1).toString();
        QString password = query.value(2).toString();
        QDateTime registerTime = query.value(3).toDateTime();

        Model::User user(id, username, password, registerTime);
        users.append(user);
    }

    if ( users.empty() ) {
        Model::User user(0, "DELETED", "DELETED", QDateTime::currentDateTime());
        users.append(user);
    }

    return users.first();
}

Model::User User::getByUserName(QString username)
{
    QList<Model::User> users ;

    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("SELECT * FROM users WHERE username = ?");
    query.addBindValue(username);
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QString username = query.value(1).toString();
        QString password = query.value(2).toString();
        QDateTime registerTime = query.value(3).toDateTime();

        Model::User user(id, username, password, registerTime);
        users.append(user);
    }

    if ( users.empty() ) {
        Model::User user(0, "DELETED", "DELETED", QDateTime::currentDateTime());
        users.append(user);
    }

    return users.first();
}

QList<Model::User> User::getAll()
{
    QList<Model::User> users ;

    DatabaseManager mgr;
    QSqlQuery query("SELECT * FROM users");
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        QString username = query.value(1).toString();
        QString password = query.value(2).toString();
        QDateTime registerTime = query.value(3).toDateTime();

        Model::User user(id, username, password, registerTime);
        users.append(user);
    }

    return users;
}

}
