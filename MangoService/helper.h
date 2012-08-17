#ifndef HELPER_H
#define HELPER_H

#include <QList>
#include <QStringList>

#include "MangoService_global.h"
#include "../MangoModel/component.h"
#include "../MangoModel/additional.h"
#include <phonon/phonon>

namespace Services {

class MANGOSERVICESHARED_EXPORT Helper
{
public:
    static QStringList fromTextToList(QString text);
    static QString fromListToText(QStringList ids);
    static QString fromComponentsToText(QList<Model::Component> components);
    static QString fromAdditionalsToText(QList<Model::Additional> additionals);
    static QString fromComponentsToTextEn(QList<Model::Component> components);
    static QString fromAdditionalsToTextEn(QList<Model::Additional> additionals);
    static void runSoundFile(QString path);

    static const QString logonSoundFile;
    static const QString logoutSoundFile;
    static const QString checkoutSoundFile;
    static const QString addingSoundFile;
    static const QString errorSoundFile;
    static const QString transitionSoundFile;
    static const QString clearSoundFile;
    static const QString removeSoundFile;
};

}

#endif // HELPER_H
