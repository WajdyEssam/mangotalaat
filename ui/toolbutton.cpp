#include "toolbutton.h"

ToolButton::ToolButton(QWidget *parent) :
    QToolButton(parent), m_state(false)
{
}

void ToolButton::setActiveState(ToolButton::ActiveState state) {
    if (state == Active)
        m_state = true;
    else
        m_state = false;
}

ToolButton::ActiveState ToolButton::activeState()
{
    return m_state ? ToolButton::Active : ToolButton::NotActive;
}
