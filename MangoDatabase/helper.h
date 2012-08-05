#ifndef DATABASE_HELPER_H
#define DATABASE_HELPER_H

#include <QList>
#include "MangoDatabase_global.h"
#include <QStringList>

namespace Database {

class MANGODATABASESHARED_EXPORT Helper
{
public:
    static QStringList fromTextToList(QString text);
    static QString fromListToText(QStringList ids);
};

}

#endif // DATABASE_HELPER_H
