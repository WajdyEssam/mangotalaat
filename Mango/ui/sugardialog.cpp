#include <QToolButton>
#include <QSignalMapper>
#include <QHBoxLayout>

#include "sugardialog.h"
#include "../../MangoModel/sugar.h"

SugarDialog::SugarDialog(QWidget *parent) :
    QDialog(parent), m_value(Model::Sugar::NormalSugar)
{
    setupUi();
    this->setWindowTitle(tr("السكر"));
}

void SugarDialog::setupUi()
{
    m_signalMapper = new QSignalMapper(this);
    connect(m_signalMapper, SIGNAL(mapped(int)), SLOT(setValue(int)));

    QToolButton* withoutSugarButton = new QToolButton;
    withoutSugarButton->setFixedSize(100, 100);
    withoutSugarButton->setText(tr("بدون سكر"));
    connect(withoutSugarButton, SIGNAL(clicked()), m_signalMapper, SLOT(map()));

    QToolButton* lessSugarButton = new QToolButton;
    lessSugarButton->setFixedSize(100, 100);
    lessSugarButton->setText(tr("سكر قليل"));
    connect(lessSugarButton, SIGNAL(clicked()), m_signalMapper, SLOT(map()));

    QToolButton* normalSugarButton = new QToolButton;
    normalSugarButton->setFixedSize(100, 100);
    normalSugarButton->setText(tr("سكر عادي"));
    connect(normalSugarButton, SIGNAL(clicked()), m_signalMapper, SLOT(map()));

    QToolButton* moreSugarButton = new QToolButton;
    moreSugarButton->setFixedSize(100, 100);
    moreSugarButton->setText(tr("سكر زيادة"));
    connect(moreSugarButton, SIGNAL(clicked()), m_signalMapper, SLOT(map()));

    m_signalMapper->setMapping(withoutSugarButton, Model::Sugar::WithoutSugar);
    m_signalMapper->setMapping(lessSugarButton, Model::Sugar::LessSugar);
    m_signalMapper->setMapping(normalSugarButton, Model::Sugar::NormalSugar);
    m_signalMapper->setMapping(moreSugarButton, Model::Sugar::MoreSugar);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(withoutSugarButton);
    layout->addWidget(lessSugarButton);
    layout->addWidget(normalSugarButton);
    layout->addWidget(moreSugarButton);
}

int SugarDialog::value() const
{
    return m_value;
}

void SugarDialog::setValue(int sugar)
{
    m_value = sugar;
    this->accept();
}
