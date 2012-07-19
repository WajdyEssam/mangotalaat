#ifndef SIZEWIDGET_H
#define SIZEWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSignalMapper>

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

public:
    void addWidgets(int itemId);

private:
    enum {
        NumButtons = 10 , ButtonsPerLine = 4
    };

    QSignalMapper *signalMapper;
    QPushButton *buttons[NumButtons];
    QGroupBox *horizontalGroupBox;

private slots:
    void setCurrentItem(int id);

signals:
    void selectItemDetail(int id);
};

#endif // SIZEWIDGET_H
