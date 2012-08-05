#ifndef PROPERTYWIDGET_H
#define PROPERTYWIDGET_H

#include <QWidget>

#include "../../MangoModel/orderdetail.h"

class QGroupBox;
class QHBoxLayout;
class QSignalMapper;
class QGridLayout;
class QToolButton;
class QVBoxLayout;
class QPushButton;
class QLineEdit;

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
    void setOrder(Model::OrderDetail orderDetail, bool isOpenedInEditMode);
    void setCurrentComponent(int);
    void setCurrentAdditional(int);
    void addItemClicked();
    void updateItemClicked();
    void removeItemClicked();
    void openKeypadDialog();

private:
    enum {
        NumButtons = 8 , ButtonsPerLine = 8
    };

    QSignalMapper *componentSignalMapper;
    QSignalMapper *additionalSignalMapper;

    QGroupBox *orderGroupBox;
    QGroupBox *componentsGroupBox;
    QGroupBox *additionalsGroupBox;

    QHBoxLayout* commandButtonHBoxLayout;
    QVBoxLayout *orderVBoxLayout;
    QGridLayout *componentsGridLayout;
    QGridLayout *additionalsGridLayout;

    QPushButton* addButton;
    QPushButton* updateButton;
    QPushButton* removeButton;

    QLineEdit* itemNameLineEdit;
    QLineEdit* itemQuantityLineEdit;
    QLineEdit* itemSizeLineEdit;
    QLineEdit* itemPriceLineEdit;
    QLineEdit* itemSugarLineEdit;
    QLineEdit* itemComponentsLineEdit;
    QLineEdit* itemAdditionalsLineEdit;
    QLineEdit* totalPriceLineEdit;

    Model::OrderDetail m_orderDetail;

    void initCommandButtons();
    void initOrder();
    void initComponents();
    void initAdditionals();

    void uncheckComponentsButtons();
    void uncheckAdditionalsButtons();
    void clearItemDetailsLineEdit();

    void recheckComponentsButtons();
    void recheckAdditionalsButtons();
    void fillItemDetialsLineEdit();
    void calculateTotalPrice();

    void showEditButton();
    void showAddButton();

    QStringList readActiveComponents();
    QStringList readActiveAdditionals();
    int readSugar();
    int readQunatity();

    void setActiveComponents();
    void setActiveAdditionals();
};

#endif // PROPERTYWIDGET_H
