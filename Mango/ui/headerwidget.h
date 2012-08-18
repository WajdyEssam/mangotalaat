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
    void addUsersActionClicked();
    void aboutSystemActionClicked();
    void returnOrderSystemActionClicked();
    void arabicLocaleClicked();
    void englishLocaleClicked();

public slots:
    void emitSignal(int id);
    void enableBackButton(bool value);

private:
    QSignalMapper *signalMapper;
    QToolButton* backButton;
    QToolButton* homeButton;
    QToolButton* reportsButton;
    QToolButton* systemButton;
    QToolButton* exitButton;

    QAction *todayLogginReportAction;
    QAction *todayOrdersReportAction;
    QAction *todayOrdersDetailsReportAction;
    QAction *generalReportAction;
    QAction *aboutSystemAction;
    QAction *closeSystemAction;
    QAction *addUsersAction;
    QAction *returnOrderSystemAction;
    QAction* arabicLocaleAct;
    QAction* englishLocaleAct;

    void init();
    void retranslateUi();
    void createToolButtons();

protected:
    void paintEvent(QPaintEvent *);
    void changeEvent(QEvent *);
};

#endif // HEADERWIDGET_H
