#ifndef KEYPAD_H
#define KEYPAD_H

#include <QDialog>

class QLCDNumber;
class QSignalMapper;

class KeypadDialog : public QDialog
{
    Q_OBJECT
public:
    KeypadDialog(QWidget* parent=0);

    int value();
    void setValue(int value);

private slots:
    void appned(int);
    void backspaceClicked();
    void clearClicked();

private:
    void setupUi();
    QLCDNumber* m_lcd;
    QSignalMapper* m_signalMapper;
};

#endif // KEYPAD_H
