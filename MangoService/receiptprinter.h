#ifndef SERVICES_RECEIPTPRINTER_H
#define SERVICES_RECEIPTPRINTER_H

#include "../MangoModel/cartorder.h"

#include "MangoService_global.h"

namespace Services
{

class MANGOSERVICESHARED_EXPORT ReceiptPrinter : public QObject
{
    Q_OBJECT

public:
    ReceiptPrinter(QObject* parent=0);
    void print(const Model::CartOrder* cartOrder);
    void printLastReceipt();
public slots:
    void exec();
private:
    static const QString printApplicationPath;
    static const QString outputFilename;
};

}

#endif // SERVICES_RECEIPTPRINTER_H
