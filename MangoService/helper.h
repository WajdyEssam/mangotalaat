#ifndef HELPER_H
#define HELPER_H

#include <QList>
#include <QStringList>

#include "MangoService_global.h"
#include "../MangoModel/component.h"
#include "../MangoModel/additional.h"

namespace Services {

class MANGOSERVICESHARED_EXPORT Helper
{
public:
    static QStringList fromTextToList(QString text);
    static QString fromListToText(QStringList ids);
    static QString fromComponentsToText(QList<Model::Component> components);
    static QString fromAdditionalsToText(QList<Model::Additional> additionals);
};

}

#endif // HELPER_H
