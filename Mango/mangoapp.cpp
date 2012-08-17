#include <QtGui/QApplication>
#include <QtCore/QDir>
#include <QtCore/QTextCodec>
#include <QtSql/QSqlDatabase>
#include <QFont>
#include <QLocale>
#include <QTranslator>
#include <QLibraryInfo>
#include <QDebug>

#include "mangoapp.h"
#include "language.h"

MangoApp::MangoApp(int &argc, char **argv) :
    QApplication(argc, argv),m_qtTranslator(0), m_mangoTranslator(0)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    this->setFont(QFont("Tahoma", 8, QFont::Normal));
    loadStylesheet();
    loadQtTranslator();
    loadMangoTranslator();
    openDBConnection();
    Settings::Language::setCurrentLanguage(Settings::Language::Arabic);
}

void MangoApp::loadStylesheet()
{
    QFile file(":/mango.qss");
    file.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(file.readAll());
    this->setStyleSheet(StyleSheet);
}

void MangoApp::loadQtTranslator()
{
    if (m_qtTranslator == 0)
        m_qtTranslator = new QTranslator;

//    qtTranslation.load("qt_" + QLocale::c().name(),
//            QLibraryInfo::location(QLibraryInfo::TranslationsPath));
//    a.installTranslator(&qtEnTranslator);

    m_qtTranslator->load("qt_ar_SA" , QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    this->installTranslator(m_qtTranslator);
}

void MangoApp::loadMangoTranslator()
{
    if (m_mangoTranslator == 0)
        m_mangoTranslator = new QTranslator;

    bool ok = m_mangoTranslator->load(QString(":/translations/Mango_ar_SA"));
    if (ok)
        this->installTranslator(m_mangoTranslator);
    else
        qDebug() << "Cannot load arabic ts";
}

void MangoApp::openDBConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mango.db");
}

void MangoApp::removeAllTranslator()
{
    if (m_mangoTranslator != 0) {
        this->removeTranslator(m_mangoTranslator);
        m_mangoTranslator = 0;
    }

    if (m_qtTranslator != 0) {
        this->removeTranslator(m_qtTranslator);
        m_qtTranslator = 0;
    }
}
