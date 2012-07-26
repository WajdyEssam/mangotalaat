#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSignalMapper>

#include "categorieswidget.h"
#include "itemswidget.h"
#include "sizewidget.h"
#include "itempropertiesdialog.h"

class HeaderWidget;
class OrderWidget;
class SlidingStackedWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum WidgetPage {
        CategoryPage = 0,
        ItemPage = 1,
        SizePage = 2
    };

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QSignalMapper *signalMapper;
    HeaderWidget *headerWidget;
    OrderWidget* orderWidget;
    SlidingStackedWidget *stackedWidget;

    CategoriesWidget* categoriesWidget;
    ItemsWidget* itemsWidget;
    SizeWidget* sizeWidget;

    QLabel *versionLabel;
    QLabel *helpLabel;

private:
    void setWindowSize();
    void createWidgetPages();
    void createDockWidgets();
    void createStatusBar();
    void establishConnections();

    void createHeaderDockWidget();
    void createOrderDockWidget();

    void setCurrentPage(WidgetPage page);

signals:
    void orderAdded(QList<Model::Order> orders);

private slots:
    void ShowHomePage();
    void reportClickedSlot();
    void orderItemClicked(QString id);
    void systemClickedSlot();

public slots:
    void selectCategorySlot(int categoryId);
    void selectItemSlot(int itemId);
    void selectItemDetialSlot(int itemDetialId);
    void updateItemDetialSlot(int itemDetialId);

private:
    QList<Model::Order> orders;
    int discount ;

    void computeTotalCash();
    void computeFree();
    void computeCupon();
    void setDiscount();
    void clearShoppingCart();
};

#endif // MAINWINDOW_H
