#ifndef LOGONSCREEN_H
#define LOGONSCREEN_H

#include <QMainWindow>
#include <QList>

#include "../../MangoModel/user.h"
#include "../../MangoService/user.h"
#include "../../MangoService/helper.h"
#include "../../ui/mainwindow.h"

namespace Ui {
class LogonScreen;
}

class LogonScreen : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit LogonScreen(QWidget *parent = 0);
    ~LogonScreen();


private slots:
    void on_logonButton_clicked();

private:
    Model::User authenicateUser(const QString& username, const QString& password);

private:
    Ui::LogonScreen *ui;
    Model::User user;
    MainWindow* applicationWindow;
};

#endif // LOGONSCREEN_H
