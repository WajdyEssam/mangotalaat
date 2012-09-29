#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QTimer>
#include "receiptprinter.h"
#include "helper.h"

namespace Services {

const QString ReceiptPrinter::printApplicationPath = "ThermalPrinterTestApp.exe";
const QString ReceiptPrinter::outputFilename = "Data.txt";

ReceiptPrinter::ReceiptPrinter(QObject *parent) :
    QObject(parent)
{
}

// Print Receipt Method
/* file format:
** cash @ discount @ total
** quantity @ size @ itemname @ sugar @ price @ component @ additional
*/
void ReceiptPrinter::print(const Model::CartOrder* cartOrder) {
    if (cartOrder->isEmpty())
        return;

    // Save order detials to file
    QString totalCashAfterDiscount = QString::number(cartOrder->totalCashAfterDiscount());
    QString totalCashBeforeDiscount = QString::number(cartOrder->totalCashBeforeDiscount());
    QString discount = QString::number(cartOrder->discount());

    QFile file(outputFilename);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream stream(&file);

        QString firstLine = totalCashAfterDiscount + " @ " + discount + " @ " + totalCashBeforeDiscount;
        stream << firstLine << endl;

        foreach(Model::OrderDetail order, cartOrder->orderDetails()) {
            QString quantity = QString::number(order.qunatity());
            QString size = order.itemDetail().size().englishName().at(0).toUpper();

            // handle GALLON size
            if ( order.itemDetail().size().id() == (int) Model::Size::GALLON_5L )
                size = "5L";
            else if (order.itemDetail().size().id() == (int) Model::Size::GALLON_1_HALF_L)
                size = "1.5L";
            else if ( order.itemDetail().size().id() == (int) Model::Size::GALLON_1L )
                size = "1L";

            // item name
            QString itemName = order.itemDetail().item().englishName();
            QString sugar = QString::number(order.sugar().id()-1);
            QString components = "#C:" + Services::Helper::fromComponentsToTextEn(order.components()) + "";
            QString additional = "#A:" + Services::Helper::fromAdditionalsToTextEn(order.additionals()) + "";
            QString price = QString::number(order.cash());

            QString itemLine = QString("%1 @ %2 @ %3 @ %4 @ %5 @ %6 @ %7")
                    .arg(quantity).arg(size).arg(itemName).arg(sugar).arg(price)
                    .arg(components).arg(additional);
            stream << itemLine << endl;
        }

        file.close();
        exec();
    }
}

void ReceiptPrinter::printLastReceipt()
{
    exec();
}

void ReceiptPrinter::exec()
{
    QStringList arg;
    arg << outputFilename;
    QProcess* p = new QProcess(this);
    p->start(printApplicationPath, arg);
    p->waitForFinished();
}


}
