#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSignalMapper>

#include "categorieswidget.h"
#include "itemswidget.h"
#include "sizewidget.h"
#include "propertywidget.h"

class HeaderWidget;
class OrderWidget;
class SlidingStackedWidget;
class QDockWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum WidgetPage {
        CategoryPage = 0,
        ItemPage = 1,
        SizePage = 2,
        PropertyPage = 3
    };

    explicit MainWindow(int aUserId, QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *);
    void changeEvent(QEvent *);

private slots:
    void showPreviousPage();
    void showHomePage();
    void addUserClicked();
    void updateUserClicked();
    void orderItemClicked(Model::OrderDetail orderDetail);
    void todayLogginReportClickedSlot();
    void todayOrdersReportClickedSlot();
    void todayOrdersDetailsReportClickedSlot();
    void generalReportClickedSlot();
    void checkoutSystemClickedSlot();
    void aboutSystemClickedSlot();
    bool logout();
    void exit();
    void returnOrderSystemClickedSlot();
    void selectCategorySlot(int categoryId);
    void selectItemSlot(int itemId);
    void selectItemDetialSlot(int itemDetialId);
    void arabicLocaleClicked();
    void englishLocaleClicked();

private:
    QSignalMapper *signalMapper;
    HeaderWidget *headerWidget;
    QDockWidget *orderDockWidget;
    OrderWidget* orderWidget;
    SlidingStackedWidget *stackedWidget;
    CategoriesWidget* categoriesWidget;
    ItemsWidget* itemsWidget;
    SizeWidget* sizeWidget;
    PropertyWidget* propertyWidget;
    QLabel *versionLabel;
    QLabel *helpLabel;
    int m_userId;

    void setWindowSize();
    void createWidgetPages();
    void createDockWidgets();
    void createStatusBar();
    void establishConnections();
    void createHeaderDockWidget();
    void createOrderDockWidget();
    void setCurrentPage(WidgetPage page);
    void addLoginEvent();
    void AddLogoutEvent();
    void disableButtonsForNotAuthenticatedUser();
};

#endif // MAINWINDOW_H
