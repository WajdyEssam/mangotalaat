#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QToolButton>

class ToolButton : public QToolButton
{
    Q_OBJECT
public:
    enum ActiveState {
        Active,
        NotActive
    };

    explicit ToolButton(QWidget *parent = 0);
    void setActiveState(ActiveState state);
    ActiveState activeState();
private:
    bool m_state;
};

#endif // TOOLBUTTON_H
