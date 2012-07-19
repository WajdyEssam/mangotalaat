#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSignalMapper>

#include "categorieswidget.h"
#include "itemswidget.h"
#include "sizewidget.h"

class HeaderWidget;
class OrderWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QSignalMapper *signalMapper;
    HeaderWidget *headerWidget;
    OrderWidget* orderWidget;
    QStackedWidget *stackedWidget;

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

private slots:

public slots:
    void selectCategorySlot(int id);
    void selectItemSlot(int id);
};

#endif // MAINWINDOW_H
