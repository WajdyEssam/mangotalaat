#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QSignalMapper>
#include "categorieswidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QSignalMapper *signalMapper;
    QWidget *headerWidget;
    QStackedWidget *stackedWidget;
    CategoriesWidget* categoriesWidget;

    QLabel *versionLabel;
    QLabel *helpLabel;

private:
    void setWindowSize();
    void addWidgets();
    void addButtons();
    void addStatusBar();
    void addSignals();

private slots:
    void setCurrentWindow(int id);

public slots:
    void selectCategorySlot(int id);
};

#endif // MAINWINDOW_H
