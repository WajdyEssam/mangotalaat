#include "loggindialog.h"
#include "ui_loggindialog.h"

LogginDialog::LogginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogginDialog)
{
    ui->setupUi(this);
    m_isAccepted = false;
}

LogginDialog::~LogginDialog()
{
    delete ui;
}

void LogginDialog::on_buttonBox_accepted()
{
    QString username = this->ui->usernameLineEdit->text().trimmed();
    QString password = this->ui->passwordLineEdit->text().trimmed();

    try {
        this->user = authenicateUser(username, password);
        this->m_isAccepted = true;
        this->hide();
    }
    catch (std::exception e) {
        this->m_isAccepted = false;
        this->hide();
    }
}

void LogginDialog::on_buttonBox_rejected()
{
    this->m_isAccepted = false;
    this->hide();
}

bool LogginDialog::isAccepted() const
{
    return this->m_isAccepted;
}

Model::User LogginDialog::authenicateUser(const QString& username, const QString& password)
{
    QList<Model::User> users = Services::User::getAll();

    foreach(Model::User user, users) {
        if ( user.userName() == username &&
             user.password() == password) {

            Model::User currentUser(user.id(), user.userName(), user.password(), user.registerDateTime());
            return currentUser;
        }
    }

    throw std::exception();
}
