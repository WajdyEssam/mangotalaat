#ifndef ITEMSWIDGET_H
#define ITEMSWIDGET_H

#include <QWidget>

namespace Ui {
    class ItemsWidget;
}

class ItemsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemsWidget(QWidget *parent = 0);
    ~ItemsWidget();

private:
    Ui::ItemsWidget *ui;
};

#endif // ITEMSWIDGET_H
