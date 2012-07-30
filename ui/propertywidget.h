#ifndef PROPERTYWIDGET_H
#define PROPERTYWIDGET_H

#include <QWidget>

#include "model/orderdetail.h"

class QGroupBox;
class QHBoxLayout;
class QSignalMapper;
class QGridLayout;
class QToolButton;
class QVBoxLayout;
class QPushButton;

class PropertyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PropertyWidget(QWidget *parent = 0);
    
signals:
    void addItem(Model::OrderDetail);
    void updateItem(Model::OrderDetail, Model::OrderDetail);
    void removeItem(Model::OrderDetail);

public slots:
    void setOrder(Model::OrderDetail order, bool isOpenedInEditMode);
    void setCurrentComponent(int);
    void setCurrentAdditional(int);
    void addItemClicked();
    void updateItemClicked();
    void removeItemClicked();

private:
    enum {
        NumButtons = 8 , ButtonsPerLine = 8
    };

    QSignalMapper *componentSignalMapper;
    QSignalMapper *additionalSignalMapper;

    QGroupBox *orderGroupBox;
    QGroupBox *componentsGroupBox;
    QGroupBox *additionalsGroupBox;

    QGridLayout *orderGridLayout;
    QGridLayout *componentsGridLayout;
    QGridLayout *additionalsGridLayout;

    QPushButton* addButton;
    QPushButton* updateButton;
    QPushButton* removeButton;

    Model::OrderDetail m_orderDetail;

    void initOrder();
    void initComponents();
    void initAdditionals();

    void uncheckComponentsButtons();
    void uncheckAdditionalsButtons();

    void recheckComponentsButtons();
    void recheckAdditionalsButtons();

    void showEditButton();
    void showAddButton();

    QStringList readActiveComponents();
    QStringList readActiveAdditionals();
    SUGAR readSugar();
    int readQunatity();
};

#endif // PROPERTYWIDGET_H
