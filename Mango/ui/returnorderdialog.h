#ifndef RETURNORDERDIALOG_H
#define RETURNORDERDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "../../MangoService/order.h"
#include "../../MangoModel/order.h"

namespace Ui {
class ReturnOrderDialog;
}

class ReturnOrderDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ReturnOrderDialog(const QDateTime& from, const QDateTime& to, QWidget *parent = 0);
    ~ReturnOrderDialog();

private slots:
    void on_cancelButton_clicked();
    void on_removeButton_clicked();

    void on_pushButton_clicked();

private:
    void initTable();
    void fillRows();

private:
    Ui::ReturnOrderDialog *ui;
    QDateTime m_from;
    QDateTime m_to;
};

#endif // RETURNORDERDIALOG_H
