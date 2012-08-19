#ifndef EMPLOYEEDIALOG_H
#define EMPLOYEEDIALOG_H

#include <QDialog>

class QTableWidget;
class QLineEdit;
class QTableWidgetItem;

class EmployeeDialog : public QDialog
{
    Q_OBJECT
public:
    enum DialogMode {
        Add,
        Update
    };

    explicit EmployeeDialog(EmployeeDialog::DialogMode mode, QWidget *parent = 0);
    
signals:
    
private slots:
    void addClicked();
    void updateClicked();
    void deleteClicked();
    void selectItem(QTableWidgetItem* item);

private:
    void setupUi(EmployeeDialog::DialogMode mode);
    void clearUi();
    void loadAllEmployees();

    QTableWidget* m_tableWidget;
    QLineEdit* m_idEdit;
    QLineEdit* m_usernameEdit;
    QLineEdit* m_passwordEdit;
};

#endif // EMPLOYEEDIALOG_H
