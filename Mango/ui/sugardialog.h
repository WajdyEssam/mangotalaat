#ifndef SUGARDIALOG_H
#define SUGARDIALOG_H

#include <QDialog>

class QSignalMapper;

class SugarDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SugarDialog(QWidget *parent = 0);
    int value() const;
signals:
    
private slots:
    void setValue(int);

private:
    void setupUi();
    QSignalMapper* m_signalMapper;
    int m_value;
};

#endif // SUGARDIALOG_H
