#include <QCoreApplication>
#include <QTextCodec>
#include <QStringList>

#include "printmanager.h"

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QString fileName = "Data.txt";

    if (app.arguments().count() > 1)
        fileName = app.arguments().at(1);

    PrintManager manager(fileName);
    manager.print();

    return 0;
}


