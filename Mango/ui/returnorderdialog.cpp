#include "returnorderdialog.h"
#include "ui_returnorderdialog.h"
#include <QDebug>

ReturnOrderDialog::ReturnOrderDialog(const QDateTime& from, const QDateTime& to, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReturnOrderDialog)
{
    this->m_from = from;
    this->m_to = to;

    ui->setupUi(this);
    this->showMaximized();
    this->initTable();
}

ReturnOrderDialog::~ReturnOrderDialog()
{
    delete ui;
}

void ReturnOrderDialog::initTable() {
    // clear table content
    this->ui->tableWidget->setRowCount(0);

    // table headers
    QStringList labels;
    labels << tr("رقم الطلب") << tr("تاريخ الطلب") << tr("نوع الطلب")
            << tr("المبلغ") << tr("الخصم") << tr("الاجمالي");

    // initialize the table with headers
    this->ui->tableWidget->setColumnCount(6);
    this->ui->tableWidget->setHorizontalHeaderLabels(labels);
    this->ui->tableWidget->verticalHeader()->hide();

    // fill data
    this->fillRows();
}

void ReturnOrderDialog::fillRows() {
    QList<Model::Order> orders = Services::Order::getNotCancelledOrdersBetweenDateTime(m_from, m_to);

    foreach(Model::Order order, orders) {
        int row = this->ui->tableWidget->rowCount();
        this->ui->tableWidget->insertRow(row);

        this->ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(order.id())));
        this->ui->tableWidget->setItem(row, 1, new QTableWidgetItem(order.createdDateTime().toString("dd/MM/yyyy h:m:s ap")));
        this->ui->tableWidget->setItem(row, 2, new QTableWidgetItem(order.orderType().arabicName()));
        this->ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(order.cash())));
        this->ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(order.discount())));
        this->ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(order.totalCash())));
    }
}

void ReturnOrderDialog::on_cancelButton_clicked()
{
    this->hide();
}

void ReturnOrderDialog::on_removeButton_clicked()
{
    QModelIndexList selectedList = ui->tableWidget->selectionModel()->selectedRows();
    for( int i=0; i<selectedList.count(); i++) {
        int row = selectedList.at(i).row();
        int orderId = this->ui->tableWidget->item(row, 0)->text().toInt();
        Model::Order order = Services::Order::getById(orderId);
        bool state = Services::Order::cancel(order);
    }

    if ( selectedList.count() > 0) {
        QMessageBox::information(this,
            "Successfull operation", "تم ارجاع الطلب بنجاح", QMessageBox::Ok, QMessageBox::Ok);
    }

    initTable();
}
