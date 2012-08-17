#include "language.h"
#include "mangoapp.h"

#include <QLocale>

namespace Settings
{

Language::Languages Language::getCurrentLanguage()
{
    QLocale locale;
    if (locale.language() == QLocale::Arabic)
        return Language::Arabic;
    else
        return Language::English;
}

void Language::setCurrentLanguage(Language::Languages language)
{
    if (language == Language::Arabic) {
        QLocale l(QLocale::Arabic, QLocale::SaudiArabia);
        QLocale::setDefault(l);
        dynamic_cast<MangoApp*>(qApp)->setLayoutDirection(Qt::RightToLeft);
        dynamic_cast<MangoApp*>(qApp)->removeAllTranslator();
        dynamic_cast<MangoApp*>(qApp)->loadQtTranslator();
        dynamic_cast<MangoApp*>(qApp)->loadMangoTranslator();

    } else {
        QLocale l(QLocale::English, QLocale::UnitedStates);
        QLocale::setDefault(l);
        dynamic_cast<MangoApp*>(qApp)->setLayoutDirection(Qt::LeftToRight);
        dynamic_cast<MangoApp*>(qApp)->removeAllTranslator();
    }
}

}
