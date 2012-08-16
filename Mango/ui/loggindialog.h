#ifndef LOGGINDIALOG_H
#define LOGGINDIALOG_H

#include "../../MangoModel/user.h"
#include "../../MangoService/user.h"

#include <QDialog>
#include <QList>

namespace Ui {
class LogginDialog;
}

class LogginDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LogginDialog(QWidget *parent = 0);
    ~LogginDialog();
    bool isAccepted() const;
    int getUserID() { return user.id(); }

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Model::User authenicateUser(const QString& username, const QString& password);

    Ui::LogginDialog *ui;
    Model::User user;
    bool m_isAccepted;
};

#endif // LOGGINDIALOG_H
