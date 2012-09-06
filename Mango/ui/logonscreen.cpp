#include "logonscreen.h"
#include "ui_logonscreen.h"

LogonScreen::LogonScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogonScreen)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowFullScreen); // WindowFullScreen
}

LogonScreen::~LogonScreen()
{
    delete ui;
}

Model::User LogonScreen::authenicateUser(const QString& username, const QString& password)
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

void LogonScreen::on_logonButton_clicked()
{
    QString username = this->ui->usernameLineEdit->text().trimmed();
    QString password = this->ui->passwordLineEdit->text().trimmed();

    try {
        this->user = authenicateUser(username, password);
        Services::Helper::runSoundFile(Services::Helper::logonSoundFile);
        this->applicationWindow = new MainWindow(this);
        this->applicationWindow->setUserID(this->user.id());
        this->applicationWindow->show();

        this->hide();
    }
    catch (std::exception e) {
        Services::Helper::runSoundFile(Services::Helper::errorSoundFile);
        QMessageBox::warning(0, "Invalid Data", "username and password is not correct!");
    }
}
