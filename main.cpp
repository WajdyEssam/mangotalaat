#include <QtGui/QApplication>
#include <QtCore/QDir>
#include <QtCore/QTextCodec>

#include "ui/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    QDir::setCurrent(QCoreApplication::applicationDirPath());

    MainWindow w;
    w.show();

    return a.exec();
}
