#ifndef HELPER_H
#define HELPER_H

#include <QList>
#include <QStringList>

namespace Services {

class Helper
{
public:
    static QStringList fromTextToList(QString text);
    static QString fromListToText(QStringList ids);
};

}

#endif // HELPER_H
