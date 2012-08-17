#include "helper.h"

namespace Services {

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

QString Helper::fromComponentsToText(QList<Model::Component> components)
{
    QString commaSeparatedText = "";

    for(int i=0; i<components.size(); i++) {
        commaSeparatedText += components.at(i).arabicName();

        if ( i < components.size() - 1 ) {
            commaSeparatedText += ", ";
        }
    }

    return commaSeparatedText;
}

QString Helper::fromAdditionalsToText(QList<Model::Additional> additionals)
{
    QString commaSeparatedText = "";

    for(int i=0; i<additionals.size(); i++) {
        commaSeparatedText += additionals.at(i).arabicName();

        if ( i < additionals.size() - 1 ) {
            commaSeparatedText += ", ";
        }
    }

    return commaSeparatedText;
}

QString Helper::fromComponentsToTextEn(QList<Model::Component> components)
{
    QString commaSeparatedText = "";

    for(int i=0; i<components.size(); i++) {
        commaSeparatedText += components.at(i).englishName();

        if ( i < components.size() - 1 ) {
            commaSeparatedText += "|";
        }
    }

    return commaSeparatedText;
}

QString Helper::fromAdditionalsToTextEn(QList<Model::Additional> additionals)
{
    QString commaSeparatedText = "";

    for(int i=0; i<additionals.size(); i++) {
        commaSeparatedText += additionals.at(i).englishName();

        if ( i < additionals.size() - 1 ) {
            commaSeparatedText += "|";
        }
    }

    return commaSeparatedText;
}

void Helper::runSoundFile(QString path) {
    Phonon::MediaObject *music =
             Phonon::createPlayer(Phonon::MusicCategory,
                                  Phonon::MediaSource(path));
     music->play();
}

const QString Helper::logonSoundFile = ":/sounds/logon.wav";
const QString Helper::logoutSoundFile= ":/sounds/logout.wav";
const QString Helper::checkoutSoundFile= ":/sounds/checkout.mp3";
const QString Helper::addingSoundFile= ":/sounds/adding.wav";
const QString Helper::errorSoundFile= ":/sounds/error.wav";
const QString Helper::transitionSoundFile= ":/sounds/tansition.mp3";
const QString Helper::clearSoundFile= ":/sounds/clear.wav";
const QString Helper::removeSoundFile= ":/sounds/remove.wav";
}
