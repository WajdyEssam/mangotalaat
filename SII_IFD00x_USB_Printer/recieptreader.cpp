#include "recieptreader.h"
#include <QFile>
#include <QStringList>
#include <QDebug>

Reciept RecieptReader::read(QString fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Unable to open file";
        return Reciept();
    }

    QString summary = file.readLine();

    Reciept r;
    r.setCash(summary.split("@").at(0));
    r.setDiscount(summary.split("@").at(1));
    r.setTotal(summary.split("@").at(2));

    while (!file.atEnd()) {

        QStringList orderLine = QString(file.readLine()).split("@");

        QString quantity = orderLine.at(0).trimmed();
        QString size = orderLine.at(1).trimmed();
        QString name = orderLine.at(2).trimmed();
        QString sugar = orderLine.at(3).trimmed();
        QString price = orderLine.at(4).trimmed();
        QString components = orderLine.at(5).trimmed();
        QString additionals = orderLine.at(6).trimmed();

        r.addItem(Item(quantity, size, name, sugar, components, additionals, price));
    }

    return r;
}
