#ifndef HEADERWIDGET_H
#define HEADERWIDGET_H

#include <QWidget>

class QSignalMapper;

class HeaderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HeaderWidget(QWidget *parent = 0);
    
signals:
    void homeClicked();
    void logoutClicked();
    void todayReportActionClicked();
    void generalReportActionClicked();
    void closeSystemActionClicked();
    void aboutSystemActionClicked();

public slots:
    void emitSignal(int id);

private:
    QSignalMapper *signalMapper;

    void init();
    void createToolButtons();

protected:
    void paintEvent(QPaintEvent *);
};

#endif // HEADERWIDGET_H
