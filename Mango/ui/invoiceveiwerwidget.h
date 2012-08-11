#ifndef INVOICEVEIWERWIDGET_H
#define INVOICEVEIWERWIDGET_H

#include <QWidget>

#include "../../MangoReports/report.h"

namespace Ui {
    class InvoiceVeiwerWidget;
}

class InvoiceVeiwerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InvoiceVeiwerWidget(Report* aReport, QWidget *parent = 0);
    ~InvoiceVeiwerWidget();

private:
    void renderReport();

private slots:
    void saveReportSlot();
    void printReportSlot();
    void cancelReportSlot();

private:
    QString htmlCode;
    Report* report;
    Ui::InvoiceVeiwerWidget *ui;
};

#endif // INVOICEVEIWERWIDGET_H
