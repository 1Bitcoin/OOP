#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QTextEdit>
#include <memory>
#include "cabin.h"
#include "controlpanel.h"

class Lift : public QObject
{
    Q_OBJECT

public:
    Lift();
    void add_call(int floor);

private:
    std::shared_ptr<Control_panel> control_panel;
    std::shared_ptr<Lift_cabin> lift_cabin;
};

#endif // LIFT_H
