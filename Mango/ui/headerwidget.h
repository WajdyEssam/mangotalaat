#ifndef HEADERWIDGET_H
#define HEADERWIDGET_H

#include <QWidget>

class QSignalMapper;
class QToolButton;

class HeaderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HeaderWidget(QWidget *parent = 0);
    
signals:
    void backClicked();
    void homeClicked();
    void logoutClicked();
    void todayLogginReportActionClicked();
    void todayOrdersReportActionClicked();
    void todayOrdersDetailsReportActionClicked();
    void generalReportActionClicked();
    void closeSystemActionClicked();
    void aboutSystemActionClicked();

public slots:
    void emitSignal(int id);
    void enableBackButton(bool value);

private:
    QSignalMapper *signalMapper;
    QToolButton* backButton;

    void init();
    void createToolButtons();

protected:
    void paintEvent(QPaintEvent *);
};

#endif // HEADERWIDGET_H
