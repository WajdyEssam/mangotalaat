#include "invoiceveiwerwidget.h"
#include "ui_invoiceveiwerwidget.h"

#include <QFile>
#include <QDebug>
#include <QPrintDialog>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QTextBrowser>
#include <QTextCodec>


InvoiceVeiwerWidget::InvoiceVeiwerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InvoiceVeiwerWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->showMaximized();

    // connections
    this->connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancelReportSlot()));
    this->connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveReportSlot()));
    this->connect(ui->printButton, SIGNAL(clicked()), this, SLOT(printReportSlot()));

    this->setWindowTitle("شاشة معاينة");
    this->renderReport();
}

InvoiceVeiwerWidget::~InvoiceVeiwerWidget()
{
    delete ui;
}


void InvoiceVeiwerWidget::renderReport() {
    this->htmlCode = getHtmlCode();
    ui->webView->setHtml(htmlCode);
}

QString InvoiceVeiwerWidget:: getHtmlCode () {
    QFile *reportFile = new QFile(":/reports/LogginReport.html");

    if ( ! reportFile->open(QIODevice::ReadOnly | QIODevice::Text) ) {
        qDebug() << "File Openining Problem";
        return "Error";
    }

    QString originalCode = reportFile->readAll();

    QString price = "100";

    QString TITLE = "Mango Talaat";
    QString COMPANY_NAME_EN = "Mango Talaat";
    QString OWNER_NAME = "Mohmmaed Allhowh";
    QString COMPANY_ADDRESS = "Riyadh, KSA";
    QString COMPANY_MOBILE = "0656444654";
    QString COMPANY_EMAIL = "test@gmail.com";

    QString reportCode = originalCode.replace("%TITLE%", TITLE).replace("%COMPANY_NAME%",COMPANY_NAME_EN)
            .replace("%OWNER_NAME%", OWNER_NAME).replace("%COMPANY_ADDRESS%", COMPANY_ADDRESS)
            .replace("%COMPANY_MOBILE%", COMPANY_MOBILE).replace("%COMPANY_EMAIL%", COMPANY_EMAIL)
            .replace("%SUCC_NUM%", price).replace("%ADD_TABLE%", getSellTable());

    return (reportCode);
}

QString InvoiceVeiwerWidget::getSellTable () {
//    QString tableBegin = "<table width=\"100%\" cellspacing=\"1\"><tbody>"
//            "<tr><th>Number of Batteries</th><th>Type of Batteries</th><th>Batteries Price</th></tr>";
//    QString tableEnd =  "</tbody></table>";

//    QString htmlTableResult = tableBegin;

//    foreach(BattaryPrice battary, sell.battariesList) {
//       QString tableRaw = QString("<tr valign=\"top\"> <td align=\"center\"><font size=\"2\">%1 أمبير</font></td> <td align=\"center\"><font size=\"2\">%2</font></td> <td align=\"center\"><font size=\"2\">%3</font></td></tr>")
//                           .arg( battary.battaryType, battary.battaryCount, battary.battaryPrice);

//       htmlTableResult += tableRaw ;
//    }

//    htmlTableResult += tableEnd;
//    return htmlTableResult;
    return "";
}



QString InvoiceVeiwerWidget:: getBillHTMLCode () {
//    QFile *reportFile = new QFile(":/reports/htmlReport.html");

//    if ( ! reportFile->open(QIODevice::ReadOnly | QIODevice::Text) ) {
//        qDebug() << "File Openining Problem";
//        return "";
//    }

//    QString originalCode = reportFile->readAll();

//    QString price = "100";

//    QString reportCode = originalCode.replace("%TITLE%", TITLE)
//            .replace("%COMPANY_NAME_EN%",COMPANY_NAME_EN).replace("%COMPANY_NAME_AR%",COMPANY_NAME_AR)
//            .replace("%OWNER_NAME%", OWNER_NAME).replace("%COMPANY_ADDRESS%", COMPANY_ADDRESS)
//            .replace("%COMPANY_MOBILE%", COMPANY_MOBILE).replace("%COMPANY_EMAIL%", COMPANY_EMAIL)
//            .replace("%CLIENT_ID%", bill.customerNo)
//            .replace("%BILL_ID%", bill.invoiceNO).replace("%CLIENT_COMPANY%", bill.companyName)
//            .replace("%CLIENT_NAME%", bill.customerName).replace("%CLIENT_MOBILE%", bill.mobile)
//            .replace("%SUCC_NUM%", price)
//            .replace("%CLIENT_ADDRESS%", bill.address).replace("%DATE%", bill.invoiceDate.toString("dd/MM/yyyy"))
//            .replace("%TIME%", bill.invoiceTime.toString("HH:mm A")).replace("%ADD_TABLE%", getBillTable());

//    return (reportCode);
    return "";
}


QString InvoiceVeiwerWidget::getBillTable () {
//    QString tableBegin = "<table width=\"100%\" cellspacing=\"1\"><tbody>"
//            "<tr><th>Number of Batteries</th><th>Type of Batteries</th><th>Voucher No</th><th>Batteries Price</th></tr>";
//    QString tableEnd =  "</tbody></table>";

//    QString htmlTableResult = tableBegin;

//    foreach(BattaryPrice battary, bill.battariesList) {
//       QString tableRaw = QString("<tr valign=\"top\"> <td align=\"center\"><font size=\"2\">%1 أمبير</font></td> <td align=\"center\"><font size=\"2\">%2</font></td> <td align=\"center\"><font size=\"2\">%3</font></td><td align=\"center\"><font size=\"2\">%4</font></td></tr>")
//                           .arg( battary.battaryType, battary.battaryCount, bill.invoiceNO, battary.battaryPrice);

//       htmlTableResult += tableRaw ;
//    }

//    htmlTableResult += tableEnd;
//    return htmlTableResult;
    return "";
}

QString InvoiceVeiwerWidget::generateHTML () {
//    QFile *reportFile = new QFile(":/reports/sanadReport.html");

//    if ( ! reportFile->open(QIODevice::ReadOnly | QIODevice::Text) ) {
//        qDebug() << "File Openining Problem";
//        return "";
//    }

//    QString originalCode = reportFile->readAll();

//    QString reportType ;

//    if ( type == INSERT )
//        reportType = "إدخال بطاريات";
//    else
//        reportType = "سحب بطاريات";

//    QString reportCode = originalCode.replace("%TITLE%", TITLE)

//            .replace("%COMPANY_LOGO%", "qrc:/reports/logo.png")
//            .replace("%COMPANY_NAME_EN%",COMPANY_NAME_EN).replace("%COMPANY_NAME_AR%",COMPANY_NAME_AR)
//            .replace("%OWNER_NAME%", OWNER_NAME).replace("%COMPANY_ADDRESS%", COMPANY_ADDRESS)
//            .replace("%COMPANY_MOBILE%", COMPANY_MOBILE).replace("%COMPANY_FAX%", COMPANY_FAX)
//            .replace("%COMPANY_EMAIL%", COMPANY_EMAIL)
//            .replace("%BILL_TYPE%",reportType).replace("%CLIENT_ID%", invoice.customerNo)
//            .replace("%BILL_ID%", invoice.invoiceNO).replace("%CLIENT_COMPANY%", invoice.companyName)
//            .replace("%CLIENT_NAME%", invoice.customerName).replace("%CLIENT_MOBILE%", invoice.mobile)
//            .replace("%CLIENT_ADDRESS%", invoice.address).replace("%DATE%", invoice.invoiceDate.toString("dd/MM/yyyy"))
//            .replace("%TIME%", invoice.invoiceTime.toString("hh:mm:ss A")).replace("%ADD_TABLE%", getHTMLTable(type));

//    return (reportCode);
    return "";
}

void InvoiceVeiwerWidget::printReportSlot(){
    QPrinter printer;
    QPrintDialog dialog(&printer, this);

    if ( dialog.exec() == QDialog::Accepted )
        ui->webView->print(&printer);
}

void InvoiceVeiwerWidget::saveReportSlot(){
    QString fileName = QFileDialog::getSaveFileName(
                this, "Save Report", "", tr("PDF File (*.pdf)"));

    if ( fileName.isEmpty() )
        return;

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    ui->webView->print(&printer);
}

void InvoiceVeiwerWidget::cancelReportSlot(){
    this->hide();
}

void InvoiceVeiwerWidget::consolePrinting(){
/*
    qDebug() << "Customer Details:";
    qDebug() << "===================" ;
    qDebug() << "\tcustomer no: " << invoice.customerNo ;
    qDebug() << "\tcustomer name: " << invoice.customerName ;
    qDebug() << "\tcustomer company: " << invoice.companyName ;
    qDebug() << "\tcustomer mobile: " << invoice.mobile ;
    qDebug() << "\tAddress: " << invoice.address ;

    qDebug() << "Invoice Details:";
    qDebug() << "===================" ;
    qDebug() << "\tInvoice no: " << invoice.invoiceNO ;
    qDebug() << "\tinvoice Date: " << invoice.invoiceDate ;
    qDebug() << "\tinvouce time: " << invoice.invoiceTime ;

    qDebug() << "Battary Details:";
    qDebug() << "===================" ;
    foreach(Battary battary, invoice.battariesList) {
        qDebug() << "\tType: " << battary.battaryType << " Count: " << battary.battaryCount ;
    }

    qDebug() << "\n\n" */;
}
