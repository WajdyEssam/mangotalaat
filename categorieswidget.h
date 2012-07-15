#ifndef CATEGORIESWIDGET_H
#define CATEGORIESWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPushButton>

namespace Ui {
    class CategoriesWidget;
}

class CategoriesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CategoriesWidget(QWidget *parent = 0);
    ~CategoriesWidget();

private:
    void addWidgets();

private:
    Ui::CategoriesWidget *ui;

    enum { NumButtons = 8 , ButtonsPerLine = 4};
    QPushButton *buttons[NumButtons];
    QGroupBox *horizontalGroupBox;
};

#endif // CATEGORIESWIDGET_H
