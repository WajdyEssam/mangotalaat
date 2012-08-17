#ifndef MANGOAPP_H
#define MANGOAPP_H

#include <QApplication>

class QTranslator;

class MangoApp : public QApplication
{
    Q_OBJECT
public:
    explicit MangoApp(int &argc, char **argv);
    void loadQtTranslator();
    void loadMangoTranslator();
    void removeAllTranslator();
    
signals:
    
public slots:
private:
    void loadStylesheet();
    void openDBConnection();

    QTranslator* m_qtTranslator;
    QTranslator* m_mangoTranslator;
};

#endif // MANGOAPP_H
