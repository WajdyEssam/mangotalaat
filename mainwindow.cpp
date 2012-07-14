#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mango.h"
#include <vector>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // get all categories
    Mango::DatabaseManager databaseManager;
    std::vector<Mango::Category> categories = databaseManager.getCategories();
    for(std::vector<Mango::Category>::iterator p = categories.begin();
            p != categories.end(); ++p ) {
        qDebug() << p->getId() << " : " << QString::fromStdString(p->getEnglishName());
    }

    // get all items in categories
    int categoryId = 3;
    std::vector<Mango::Item> items = databaseManager.getItemsInCategory(categoryId);
    for(std::vector<Mango::Item>::iterator p = items.begin(); p != items.end(); ++p ) {
        qDebug() << p->getId() << " : " << QString::fromStdString(p->getEnglishName()) << " " << p->getPrice();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
