#include <QPrinter>
#include <QPainter>
#include <QDateTime>
#include <QDebug>

#include "printmanager.h"
#include "recieptreader.h"

PrintManager::PrintManager(QString fileName)
{
    m_reciept = RecieptReader::read(fileName);

    printer.setColorMode(QPrinter::GrayScale);
    printer.setCopyCount(1);
    printer.setPaperSize(QPrinter::Letter);
}

void PrintManager::print()
{
    QString content = getOrderLineTitle() + getOrderLine() + getFooter();

    QPainter painter;
    painter.begin(&printer);

    painter.setFont(QFont("Tahoma", 10, QFont::Bold));
    painter.drawText(30, 0, 500, 20, Qt::AlignLeft, getHeader());

    painter.setFont(QFont("Tahoma", 9));
    painter.drawText(30, 25, 500, 50, Qt::AlignLeft, getSubHeader());

    painter.setFont(QFont("Consolas", 8, QFont::Bold));
    painter.drawText(0, 55, 500, 1000, Qt::AlignLeft, content);

    painter.end();
}


QString PrintManager::getHeader()
{
    QString header = "              Mango Talaat\n";
    return header;
}

QString PrintManager::getSubHeader()
{
   return "         Riyadh, Gadheer Branch\n\n";
}

QString PrintManager::getOrderLineTitle()
{
    return QString("%1  %2/%3     %4           %5\n %6 \n")
            .arg("#").arg("Size")
            .arg("Sugar").arg("Item").arg("$")
            .arg("_________________________________");
}

QString PrintManager::getWithSpace(QString name, int max, bool leftJustified)
{
    qDebug() << "name: " << name << " length: " << name.size();

    if (leftJustified)
        name = name.leftJustified(max, ' ');
    else
        name = name.rightJustified(max, ' ');

    return name;
}

QString PrintManager::getFooter() const
{
    QString footer = QString("%1%2SR\n%3%4SR\n%5%6SR\n\n")
            .arg(getWithSpace("Cash:", 20, false))
            .arg(getWithSpace(m_reciept.cash(), 5, false))
            .arg(getWithSpace("Discount:", 20, false))
            .arg(getWithSpace(m_reciept.discount(), 5, false))
            .arg(getWithSpace("Total:", 20, false))
            .arg(getWithSpace(m_reciept.total().replace("\n", " "), 5, false));

    footer += "               شكرا لزيارتك\n";
    footer += QString("%1").arg(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss AP"));

    return footer;
}

QString PrintManager::getOrderLine() const {
    QString result;

    foreach (Item item, m_reciept.items()) {

        QString size_sugar = item.size() + "/" + item.sugar();

        QString orderLine = QString("%1%2%3%4")
                .arg(getWithSpace(item.quantity(), 3))
                .arg(getWithSpace(size_sugar, 5))
                .arg(getWithSpace(item.name(), 25))
                .arg(item.price());

        result.append(orderLine).append("\n");
    }

    return result.append("\n");
}
