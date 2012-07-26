#include <QtGui/QApplication>
#include <QtCore/QDir>
#include <QtCore/QTextCodec>
#include <QtSql/QSqlDatabase>

#include "ui/mainwindow.h"

void loadStylesheet();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QDir::setCurrent(QCoreApplication::applicationDirPath());

    // load style sheet
    loadStylesheet();

    // Set Database name
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mango.db");

    // ask for authentication
    int userId = 1; // admin

    MainWindow w(userId);
    w.show();

    return a.exec();
}

void loadStylesheet() {
    QFile file(":/mango.qss");
    file.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(StyleSheet);
}
