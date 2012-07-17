#include <QtGui/QApplication>
#include <QtCore/QDir>
#include <QtCore/QTextCodec>

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

    MainWindow w;
    w.show();

    return a.exec();
}

void loadStylesheet() {
    QFile file(":/mango.qss");
    file.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(StyleSheet);
}
