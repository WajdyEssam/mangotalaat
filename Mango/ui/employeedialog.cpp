#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

#include "employeedialog.h"

#include "../../MangoModel/user.h"
#include "../../MangoService/user.h"
#include "../../MangoService/order.h"
#include "../../MangoModel/order.h"

EmployeeDialog::EmployeeDialog(EmployeeDialog::DialogMode mode, QWidget *parent) :
    QDialog(parent)
{
    setupUi(mode);
    loadAllEmployees();
}

void EmployeeDialog::setupUi(EmployeeDialog::DialogMode mode)
{
    QLabel* idLabel = new QLabel(tr("id:"));
    QLabel* usernameLabel = new QLabel(tr("username:"));
    QLabel* passwordLabel = new QLabel(tr("password:"));

    m_idEdit = new QLineEdit;
    m_idEdit->setReadOnly(true);

    m_usernameEdit = new QLineEdit;
    m_passwordEdit = new QLineEdit;

    QHBoxLayout* upperLayout = new QHBoxLayout;
    upperLayout->addWidget(idLabel);
    upperLayout->addWidget(m_idEdit);
    upperLayout->addWidget(usernameLabel);
    upperLayout->addWidget(m_usernameEdit);
    upperLayout->addWidget(passwordLabel);
    upperLayout->addWidget(m_passwordEdit);

    m_tableWidget = new QTableWidget;
    m_tableWidget->setAlternatingRowColors(true);
    m_tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(m_tableWidget, SIGNAL(itemClicked(QTableWidgetItem*)), SLOT(selectItem(QTableWidgetItem*)));

    QPushButton* addButton = new QPushButton(tr("Add"));
    connect(addButton, SIGNAL(clicked()), SLOT(addClicked()));

    QPushButton* removeButton = new QPushButton(tr("Delete"));
    connect(removeButton, SIGNAL(clicked()), SLOT(deleteClicked()));

    QPushButton* updateButton = new QPushButton(tr("Update"));
    connect(updateButton, SIGNAL(clicked()), SLOT(updateClicked()));

    QPushButton* closeButton = new QPushButton(tr("Close"));
    connect(closeButton, SIGNAL(clicked()), SLOT(accept()));

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(addButton);
    buttonsLayout->addWidget(removeButton);
    buttonsLayout->addWidget(updateButton);
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(closeButton);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(upperLayout);
    layout->addWidget(m_tableWidget);
    layout->addLayout(buttonsLayout);

    this->setLayout(layout);

    if (mode == Add) {
        removeButton->setVisible(false);
        updateButton->setVisible(false);
        m_tableWidget->setVisible(false);

        idLabel->setVisible(false);
        m_idEdit->setVisible(false);

        this->setWindowTitle(tr("Add user"));
    } else {
        addButton->setVisible(false);

        this->setWindowTitle(tr("Update users"));
    }
}

void EmployeeDialog::clearUi()
{
    m_idEdit->clear();
    m_usernameEdit->clear();
    m_passwordEdit->clear();
}

void EmployeeDialog::addClicked()
{
    QString username = m_usernameEdit->text().trimmed();
    QString password = m_passwordEdit->text().trimmed();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, tr("Unable to add new employee"), tr("Please provide correct information"));
        return;
    }

    Model::User user(0, username, password, QDateTime::currentDateTime());
    bool ok = Services::User::add(user);

    if (ok) {
        QMessageBox::information(this, tr("Operation done successfully"), tr("Employee Added Succefully"));
        clearUi();
    } else {
        QMessageBox::warning(this, tr("Unable to add new employee"), tr("Please make sure you add unique username"));
    }
}

void EmployeeDialog::updateClicked()
{
    int id = m_idEdit->text().trimmed().toInt();
    QString username = m_usernameEdit->text().trimmed();
    QString password = m_passwordEdit->text().trimmed();

    if (username.isEmpty() || password.isEmpty() || id == 0) {
        QMessageBox::warning(this, tr("Unable to update employee"), tr("Please select an employee from list to update"));
        return;
    }

    Model::User user = Services::User::getById(id);
    user.setUserName(username);
    user.setPassword(password);

    bool ok = Services::User::update(user);

    if (ok) {
        QMessageBox::information(this, tr("Operation done successfully"), tr("Employee Updated Succefully"));
        clearUi();
        loadAllEmployees();
    } else {
        QMessageBox::warning(this, tr("Unable to update employee"), tr("Please make sure you set unique username"));
    }

}

void EmployeeDialog::deleteClicked()
{
    int id = m_idEdit->text().trimmed().toInt();
    QString username = m_usernameEdit->text().trimmed();
    QString password = m_passwordEdit->text().trimmed();

    if (username.isEmpty() || password.isEmpty() || id == 0) {
        QMessageBox::warning(this, tr("Unable to delete employee"), tr("Please select an employee from list to delete"));
        return;
    }

    if ( id == 1 ) {
        QMessageBox::warning(this, tr("Unable to delete Admin"), tr("You Cannot delete the admin of the system"));
        return;
    }

    // check if user have order records, then do not delete this user
    QList<Model::Order> orders = Services::Order::getByUserId(id);

    if ( !orders.isEmpty()) {
        QMessageBox::warning(this, tr("Unable to this user"), tr("this user have order records in the database"));
        return;
    }

    bool ok = Services::User::removeById(id);

    if (ok) {
        QMessageBox::information(this, tr("Operation done successfully"), tr("Employee Deleted Succefully"));
        clearUi();
        loadAllEmployees();
    } else {
        QMessageBox::warning(this, tr("Unable to delete employee"), tr("Please select an employee from list to delete"));
    }
}

void EmployeeDialog::selectItem(QTableWidgetItem *item)
{
    clearUi();
    int row = item->row();
    m_idEdit->setText(m_tableWidget->item(row, 0)->text());
    m_usernameEdit->setText(m_tableWidget->item(row, 1)->text());
    m_passwordEdit->setText(m_tableWidget->item(row, 2)->text());
}

void EmployeeDialog::loadAllEmployees()
{
    QList<Model::User> users = Services::User::getAll();
    if (users.count() == 0)
        return;

    m_tableWidget->clear();
    m_tableWidget->setColumnCount(3);
    m_tableWidget->setHorizontalHeaderLabels(QStringList() << tr("id") << tr("user name") << tr("password"));
    m_tableWidget->setRowCount(users.count());

    int row = 0;

    foreach (Model::User user, users) {
        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(user.id()));
        QTableWidgetItem* usernameItem = new QTableWidgetItem(user.userName());
        QTableWidgetItem* passwordItem = new QTableWidgetItem(user.password());

        m_tableWidget->setItem(row, 0, idItem);
        m_tableWidget->setItem(row, 1, usernameItem);
        m_tableWidget->setItem(row, 2, passwordItem);

        row++;
    }
}
