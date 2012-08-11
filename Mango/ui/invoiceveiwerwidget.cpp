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

InvoiceVeiwerWidget::InvoiceVeiwerWidget(Report* aReport, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InvoiceVeiwerWidget)
{
    ui->setupUi(this);
    this->report = aReport;

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
    this->htmlCode = this->report->getHTML();
    ui->webView->setHtml(htmlCode);
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
