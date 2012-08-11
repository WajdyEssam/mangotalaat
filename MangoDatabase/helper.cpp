#include "helper.h"

namespace Database {

QStringList Helper::fromTextToList(QString text)
{
    QStringList tmp;

    if ( !text.isEmpty() )
        tmp = text.split(",");

    return tmp;
}

QString Helper::fromListToText(QStringList ids)
{
    QString commaSeparatedId = "";

    for(int i=0; i<ids.size(); i++) {
        commaSeparatedId += ids.at(i);

        if ( i < ids.size() - 1 ) {
            commaSeparatedId += ",";
        }
    }

    return commaSeparatedId;
}

}
