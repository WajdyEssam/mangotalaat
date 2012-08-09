#ifndef SIZEWIDGET_H
#define SIZEWIDGET_H

#include <QWidget>

class QGroupBox;
class QHBoxLayout;
class QSignalMapper;
class QGridLayout;
class QToolButton;
class QVBoxLayout;

class SizeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SizeWidget(QWidget *parent = 0);
    ~SizeWidget();

    void createItemSizes(int itemId);

signals:
    void selectItemDetail(int id);

private:
    enum {
        NumButtons = 10 , ButtonsPerLine = 4
    };

    QSignalMapper *signalMapper;
    QGroupBox *horizontalGroupBox;
    QGridLayout *layout;
    QHBoxLayout* containerLayout;
    QVBoxLayout* subContainerLayout;

    void removeItemSizes();
};

#endif // SIZEWIDGET_H
