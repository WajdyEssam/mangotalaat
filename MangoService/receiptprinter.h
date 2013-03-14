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
    void openCashDrawer();
public slots:
    void exec();
private:
    static const QString printApplicationPath;
    static const QString outputFilename;
    static const QString cashDrawerPath;
};

}

#endif // SERVICES_RECEIPTPRINTER_H
