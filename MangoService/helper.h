#ifndef HELPER_H
#define HELPER_H

#include <QList>
#include <QStringList>
#include "MangoService_global.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT Helper
{
public:
    static QStringList fromTextToList(QString text);
    static QString fromListToText(QStringList ids);
};

}

#endif // HELPER_H
