#include <QtGui/QApplication>
#include <QtCore/QDir>
#include <QtCore/QTextCodec>
#include <QtSql/QSqlDatabase>
#include <QFont>

#include "ui/mainwindow.h"
#include "ui/loggindialog.h"

void loadStylesheet();
void loadFonts();

int main(int argc, char *argv[])
{
    // TODO: Port to Qt5.

    QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QDir::setCurrent(QCoreApplication::applicationDirPath());

    a.setLayoutDirection(Qt::RightToLeft);
    //a.setFont(QFont("Droid Arabic Naskh", 8, QFont::Normal));
    a.setFont(QFont("Times New Roman", 12, QFont::Normal));

    // load style sheet
    loadStylesheet();

    // NOTE: move db connection to db layer
    // Set Database name
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mango.db");

#if defined(NO_DEBUG)
    // ask for authentication
    LogginDialog dialog;
    dialog.exec();

    if ( !dialog.isAccepted() ) {
        QMessageBox::warning(0, "Invalid Data", "username and password is not correct"
                             " ,System will closed now!");
        return (0);
    }
    int userId = dialog.getUserID();
#else
    int userId = 1;
#endif

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

void loadFonts() {

    QStringList list;
    list << "DroidNaskh-Regular.ttf" << "DroidNaskh-Bold.ttf" ;

    int fontID = -1;
    bool fontWarningShown = false;

    for (QStringList::const_iterator constIterator = list.constBegin(); constIterator != list.constEnd(); ++constIterator) {
        QFile res(":/data/fonts/" + *constIterator);
        if (res.open(QIODevice::ReadOnly) == false) {
            if (fontWarningShown == false) {
                QMessageBox::warning(0, "Application", "Unable to load fonts");
                fontWarningShown = true;
            }
        } else {
            fontID = QFontDatabase::addApplicationFontFromData(res.readAll());
            if (fontID == -1 && fontWarningShown == false) {
                QMessageBox::warning(0, "Application", "Unable to load fonts");
                fontWarningShown = true;
            }
        }
    }
}
