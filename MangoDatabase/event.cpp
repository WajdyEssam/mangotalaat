#include "event.h"
#include "databasemanager.h"

namespace Database {


bool Event::add(Model::Event event)
{
    DatabaseManager mgr;
    QSqlQuery query;

    query.prepare("INSERT INTO events_logging(user_id, event_time, event_type) VALUES(?,?,?)");
    query.addBindValue(event.user().id());
    query.addBindValue(event.createdDateTime());
    query.addBindValue(event.eventType());

    return query.exec();
}

QList<Model::Event> Event::getAll()
{
    QList<Model::Event> events;

    DatabaseManager mgr;
    QSqlQuery query("SELECT * from events_logging");
    query.exec();

    while(query.next()) {
        int id = query.value(0).toInt();
        int user_id = query.value(1).toInt();
        QDateTime event_time = query.value(2).toDateTime();
        int event_type = query.value(3).toInt();

        Model::User user(user_id);

        Model::Event::EventTypes eventType;

        if (event_type == 1)
            eventType = Model::Event::Login;
        else
            eventType = Model::Event::Logout;

        Model::Event event(id, user, event_time, eventType);

        events.append(event);
    }

    return events;
}

QList<Model::Event> Event::getBetweenDateTime(QDateTime from, QDateTime to)
{
    QList<Model::Event> events;

    DatabaseManager mgr;
    QSqlQuery query("SELECT * from events_logging");

    while(query.next()) {
        int id = query.value(0).toInt();
        int user_id = query.value(1).toInt();
        QDateTime event_time = query.value(2).toDateTime();
        int event_type = query.value(3).toInt();

        Model::User user(user_id);

        Model::Event::EventTypes eventType;

        if (event_type == 1)
            eventType = Model::Event::Login;
        else
            eventType = Model::Event::Logout;

        Model::Event event(id, user, event_time, eventType);

        if ( event_time >= from && event_time <= to)
            events.append(event);
    }

    return events;
}


}
