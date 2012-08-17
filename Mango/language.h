#ifndef LANGUAGE_H
#define LANGUAGE_H

namespace Settings {

class Language
{
public:
    enum Languages{
        Arabic,
        English
    };

    static Language::Languages getCurrentLanguage();
    static void setCurrentLanguage(Language::Languages language);
};

}

#endif // LANGUAGE_H
