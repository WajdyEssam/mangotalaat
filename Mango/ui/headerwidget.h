#ifndef HEADERWIDGET_H
#define HEADERWIDGET_H

#include <QWidget>
#include <QApplication>
#include <QToolButton>
#include <QHBoxLayout>
#include <QPainter>
#include <QSignalMapper>
#include <QAction>
#include <QMenu>

class QSignalMapper;
class QToolButton;

class HeaderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HeaderWidget(QWidget *parent = 0);
    void enableUserButtons();
    void enableAdminButtons();

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
    void returnOrderSystemActionClicked();

public slots:
    void emitSignal(int id);
    void enableBackButton(bool value);

private:
    QSignalMapper *signalMapper;
    QToolButton* backButton;
    QToolButton* reportsButton;
    QAction *aboutSystemAction;
    QAction *closeSystemAction;

    void init();
    void createToolButtons();

protected:
    void paintEvent(QPaintEvent *);
};

#endif // HEADERWIDGET_H
