#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSignalMapper>

#include "categorieswidget.h"
#include "itemswidget.h"
#include "sizewidget.h"
#include "propertywidget.h"

#include "../../MangoModel/orderdetail.h"

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

    explicit MainWindow(int id, QMainWindow* parentWindow, QWidget *parent = 0);
    ~MainWindow();

signals:
    void orderDetailUpdated(QList<Model::OrderDetail> orderDetails);

protected:
    void closeEvent(QCloseEvent *);
    void changeEvent(QEvent *);

private slots:
    void showPreviousPage();
    void showHomePage();
    void addUserClicked();
    void updateUserClicked();
    void orderItemClicked(QString orderIndexId);
    void todayLogginReportClickedSlot();
    void todayOrdersReportClickedSlot();
    void todayOrdersDetailsReportClickedSlot();
    void generalReportClickedSlot();
    void checkoutSystemClickedSlot();
    void aboutSystemClickedSlot();
    bool logout();
    void exit();
    void returnOrderSystemClickedSlot();
    void applyOrderClickedSlot();
    void cancelOrderClickedSlot();
    void applyDiscountOrderClickedSlot();
    void selectCategorySlot(int categoryId);
    void selectItemSlot(int itemId);
    void selectItemDetialSlot(int itemDetialId);
    void arabicLocaleClicked();
    void englishLocaleClicked();
    //void updateItemDetialSlot(Model::OrderDetail order);
    void addItemToCart(Model::OrderDetail);
    void updateItemInCart(Model::OrderDetail);
    void removeItemFromCart(Model::OrderDetail);
    void printReceipt(int discount);
    void anotherPrinting();

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
    QList<Model::OrderDetail> orderDetails;
    int m_userId;
    Model::OrderDetail getOrderByIndexId(QString indexId);

    QMainWindow* m_parentWindow;

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
    void computeTotalCash(int discount, Model::OrderType::OrderTypes orderType);
    void clearShoppingCart();
    void disableButtonsForNotAuthenticatedUser();
};

#endif // MAINWINDOW_H
