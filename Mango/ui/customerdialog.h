#ifndef CUSTOMERDIALOG_H
#define CUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
    class CustomerDialog;
}

class QSqlTableModel;
class QDataWidgetMapper;

class CustomerDialog : public QDialog
{
    Q_OBJECT
public:
    enum {
        EmployeeNo,
        EmployeeName,
        EmployeePassword,
        Date
    };

    CustomerDialog(QWidget* parent=0);
    ~CustomerDialog();
private slots:
    void disableFilter(bool);
    void disableArrows(int);
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_saveButton_clicked();
signals:
    void customerUpdated();
private:
    void createCustomerModel();
    void createCustomerView();
    void createCustomerUiMapper();
    int employeeNo();
    Ui::CustomerDialog* ui;
    QSqlTableModel* tableModel;
    QDataWidgetMapper* mapper;
};

#endif // CUSTOMERDIALOG_H
