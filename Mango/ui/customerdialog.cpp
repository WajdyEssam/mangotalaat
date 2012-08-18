#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QDataWidgetMapper>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QDate>
#include "customerdialog.h"
#include "ui_customerdialog.h"

CustomerDialog::CustomerDialog(QWidget *parent):
        QDialog(parent),ui(new Ui::CustomerDialog)
{
    ui->setupUi(this);
    ui->tableView->hide();
    ui->customerNoLineEdit->setReadOnly(true);
    ui->searchButton->setChecked(false);
    ui->addButton->setShortcut(tr("Ctrl+N"));
    ui->searchButton->setShortcut(tr("Ctrl+F"));
    ui->saveButton->setShortcut(tr("Ctrl+S"));
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    createCustomerModel();
    createCustomerUiMapper();
    createCustomerView();

    connect(ui->nextButton,SIGNAL(clicked()),mapper,SLOT(toNext()));
    connect(ui->previousButton,SIGNAL(clicked()),mapper,SLOT(toPrevious()));
    connect(ui->searchButton,SIGNAL(toggled(bool)),this,SLOT(disableFilter(bool)));
}

CustomerDialog::~CustomerDialog() {
    delete ui;
}

void CustomerDialog::createCustomerModel() {
    tableModel = new QSqlTableModel(this);
    tableModel->setTable("users");
    tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    tableModel->select();

    tableModel->setHeaderData(EmployeeNo,Qt::Horizontal,"رقم الموظف");
    tableModel->setHeaderData(EmployeeName,Qt::Horizontal,"اسم الموظف");
    tableModel->setHeaderData(EmployeePassword,Qt::Horizontal,"الرقم السري");
}

void CustomerDialog::createCustomerUiMapper() {
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    mapper->setModel(tableModel);
    mapper->addMapping(ui->customerNoLineEdit,EmployeeNo);
    mapper->addMapping(ui->usernameLineEdit,EmployeeName);
    mapper->addMapping(ui->passwordLineEdit,EmployeePassword);

    connect(mapper,SIGNAL(currentIndexChanged(int)),ui->tableView,SLOT(selectRow(int)));
    connect(mapper,SIGNAL(currentIndexChanged(int)),this,SLOT(disableArrows(int)));

    mapper->toFirst();
}

void CustomerDialog::createCustomerView() {
    ui->tableView->setModel(tableModel);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);;
    ui->tableView->setColumnHidden(Date,true);

    connect(ui->tableView->selectionModel(),SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),mapper,SLOT(setCurrentModelIndex(QModelIndex)));
}

void CustomerDialog::on_saveButton_clicked() {
    int row = mapper->currentIndex();
    mapper->submit();
    if (!tableModel->submitAll())
        QMessageBox::warning(this,"Data is not saved","Unable to update employee information");
    mapper->setCurrentIndex(row);
    emit customerUpdated();
    QMessageBox::information(this,"تم العملية بنجاح","تم اضافة الموظف");
}

void CustomerDialog::on_addButton_clicked() {
    mapper->submit();
    int row = tableModel->rowCount();
    tableModel->insertRow(row);
    tableModel->setData(tableModel->index(row,EmployeeNo),employeeNo());
    tableModel->setData(tableModel->index(row,EmployeeName),"");
    tableModel->setData(tableModel->index(row,EmployeePassword),"");
    tableModel->setData(tableModel->index(row,Date),QDate::currentDate());

    mapper->setCurrentIndex(row);
}

int CustomerDialog::employeeNo() {
    QSqlQuery query;
    query.exec("SELECT MAX(id) FROM users");
    int value = 0;
    if (query.next())
        value = query.value(0).toInt()+1;
    return value;
}

void CustomerDialog::on_deleteButton_clicked() {
    int row = mapper->currentIndex();

    QSqlQuery query;
    query.exec("SELECT * FROM orders WHERE user_id = " + row);
    bool haveRecords = false;
    if (query.next()) {
        haveRecords = true;
    }

    if ( haveRecords ) {
        QMessageBox::warning(this,"لا يمكن حذف الموظف","الموظف لديه طلبات في النظام لا يمكن حذفها، يمكن تغيير رقمه سري فقط");
    }
    else {
        mapper->submit();
        tableModel->removeRow(row);
        if (!tableModel->submitAll())
            QMessageBox::warning(this,"Data is not removed","Unable to remove car");
        mapper->setCurrentIndex(qMin(row,tableModel->rowCount()-1));
    }
}

void CustomerDialog::disableFilter(bool on) {
    if (!on) {
        //! TODO: restore the current index after disable filter.
        tableModel->setFilter("");
    }
}

void CustomerDialog::disableArrows(int index) {
    // Check up arrow
    if (index == 0)
        ui->previousButton->setEnabled(false);
    else
        ui->previousButton->setEnabled(true);

    // Check down arrow
    if (index == tableModel->rowCount()-1)
        ui->nextButton->setEnabled(false);
    else
        ui->nextButton->setEnabled(true);
}
