#ifndef SIZEWIDGET_H
#define SIZEWIDGET_H

#include <QWidget>

namespace Ui {
    class SizeWidget;
}

class SizeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SizeWidget(QWidget *parent = 0);
    ~SizeWidget();

private:
    Ui::SizeWidget *ui;
};

#endif // SIZEWIDGET_H
