#include <QLCDNumber>
#include <QToolButton>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QSignalMapper>

#include "keypaddialog.h"

KeypadDialog::KeypadDialog(QWidget* parent) :
    QDialog(parent)
{
    setupUi();
    this->setWindowTitle(tr("Keypad"));
}

int KeypadDialog::value()
{
    return (int)m_lcd->value();
}

void KeypadDialog::setValue(int value)
{
    m_lcd->display(value);
}

void KeypadDialog::setupUi()
{
    m_lcd = new QLCDNumber;
    m_lcd->setFixedHeight(100);
    m_signalMapper = new QSignalMapper(this);
    connect(m_signalMapper, SIGNAL(mapped(int)), SLOT(appned(int)));

    QGridLayout* buttonsGridLayout = new QGridLayout;

    for (int i=0;i<10; ++i) {
        QToolButton* button = new QToolButton;
        button->setFixedSize(60, 60);
        button->setText(QString::number(i));
        buttonsGridLayout->addWidget(button, i / 3,  i % 3);
        m_signalMapper->setMapping(button, i);
        connect(button, SIGNAL(clicked()), m_signalMapper, SLOT(map()));
    }

    QToolButton* acceptButton = new QToolButton;
    acceptButton->setFixedSize(60, 60);
    acceptButton->setText(tr("Ok"));
    connect(acceptButton, SIGNAL(clicked()), SLOT(accept()));

    QToolButton* backspaceButton = new QToolButton;
    backspaceButton->setFixedSize(20, 20);
    backspaceButton->setText(("<-"));
    connect(backspaceButton, SIGNAL(clicked()), SLOT(backspaceClicked()));

    QToolButton* clearButton = new QToolButton;
    clearButton->setFixedSize(60, 60);
    clearButton->setText(("Clear"));
    connect(clearButton, SIGNAL(clicked()), SLOT(clearClicked()));

    //buttonsGridLayout->addWidget(backspaceButton, 4, 0, 1, 3);
    buttonsGridLayout->addWidget(clearButton, 3, 1);
    buttonsGridLayout->addWidget(acceptButton, 3, 2);


    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_lcd);
    layout->addLayout(buttonsGridLayout);
}

void KeypadDialog::appned(int keyValue)
{
    int value = (int)m_lcd->value();
    value = (value * 10) + keyValue;
    m_lcd->display(value);
}

void KeypadDialog::backspaceClicked()
{
    int value = (int)m_lcd->value();
    value = value / 10;
    m_lcd->display(value);
}

void KeypadDialog::clearClicked()
{
    m_lcd->display(0);
}
