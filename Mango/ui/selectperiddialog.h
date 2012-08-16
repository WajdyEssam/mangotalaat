#ifndef SELECTPERIDDIALOG_H
#define SELECTPERIDDIALOG_H

#include <QDialog>
#include <QDateTime>

namespace Ui {
class SelectPeridDialog;
}

class SelectPeridDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SelectPeridDialog(QWidget *parent = 0);
    ~SelectPeridDialog();
    
    QDateTime from();
    QDateTime to();
    bool isAccepted();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::SelectPeridDialog *ui;
    QDateTime m_from, m_to;
    bool m_accept;
};

#endif // SELECTPERIDDIALOG_H
