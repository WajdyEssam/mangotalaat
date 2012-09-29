#include "returnorderdialog.h"
#include "ui_returnorderdialog.h"

#include "../../MangoService/orderdetail.h"
#include "../../MangoService/receiptprinter.h"

#include "../../MangoModel/cartorder.h"
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
    labels << tr("Order No") << tr("Order Date") << tr("Order Type")
            << tr("Price") << tr("Discount") << tr("Total");

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
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this,"لا يمكن ارجاع الطلب","فضلا اختر أحد الطلبات قبل عملية الحذف");
        return ;
    }

    QMessageBox::StandardButton button = QMessageBox::information(this,
                                                                  tr("Return Order from the system"),
                                                                  tr("Are you sure you want to cancel the order?"),
                                                                   QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if (button == QMessageBox::No)
        return;

    QModelIndexList selectedList = ui->tableWidget->selectionModel()->selectedRows();
    for( int i=0; i<selectedList.count(); i++) {
        int row = selectedList.at(i).row();
        int orderId = this->ui->tableWidget->item(row, 0)->text().toInt();
        Model::Order order = Services::Order::getById(orderId);
        Services::Order::cancel(order);
    }

    if ( selectedList.count() > 0) {
        QMessageBox::information(this, tr("Operation done successfully"), tr("Order it returned successfully"), QMessageBox::Ok, QMessageBox::Ok);
    }

    initTable();
}

void ReturnOrderDialog::on_pushButton_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this,"لا يمكن طباعة الفاتورة","يجب تحديد أحد الطلبات");
        return ;
    }

    QMessageBox::StandardButton button = QMessageBox::information(this,
                                                                  tr("Print Order from the system"),
                                                                  tr("Are you sure you want to re-print the order?"),
                                                                   QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if (button == QMessageBox::No)
        return;


    QModelIndexList selectedList = ui->tableWidget->selectionModel()->selectedRows();
    for( int i=0; i<selectedList.count(); i++) {
        int row = selectedList.at(i).row();
        int orderId = this->ui->tableWidget->item(row, 0)->text().toInt();

        Model::CartOrder cartOrder;
        foreach (Model::OrderDetail orderDetail, Services::OrderDetail::getByOrderId(orderId)) {
            cartOrder.add(orderDetail);
        }

        Services::ReceiptPrinter printer(this);
        printer.print(&cartOrder);
    }

}
