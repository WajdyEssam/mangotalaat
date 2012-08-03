#include "helper.h"

namespace Services {

QStringList Helper::fromTextToList(QString text)
{
    return text.split(",");
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
