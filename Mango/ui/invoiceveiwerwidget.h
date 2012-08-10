#ifndef INVOICEVEIWERWIDGET_H
#define INVOICEVEIWERWIDGET_H

#include <QWidget>

namespace Ui {
    class InvoiceVeiwerWidget;
}

class InvoiceVeiwerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InvoiceVeiwerWidget(QWidget *parent = 0);
    ~InvoiceVeiwerWidget();

private:
    void renderReport();
    QString generateHTML();

    QString getHtmlCode();
    QString getSellTable();

    QString getBillHTMLCode();
    QString getBillTable();

    void consolePrinting();

private slots:
    void saveReportSlot();
    void printReportSlot();
    void cancelReportSlot();

private:
    QString htmlCode;
    Ui::InvoiceVeiwerWidget *ui;
};

#endif // INVOICEVEIWERWIDGET_H
