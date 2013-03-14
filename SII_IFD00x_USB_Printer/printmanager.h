#ifndef PRINTMANAGER_H
#define PRINTMANAGER_H

#include <QPrinter>
#include "reciept.h"

class PrintManager
{
public:
    PrintManager(QString fileName);
    void print();

private:

    static QString getHeader();
    static QString getSubHeader();
    static QString getOrderLineTitle();
    static QString getWithSpace(QString name, int max, bool leftJustified = true);

    QString getFooter() const;
    QString getOrderLine() const;

    QPrinter printer;
    Reciept m_reciept;
};

#endif // PRINTMANAGER_H
