#include "lift.h"

Lift::Lift() : control_panel(std::make_shared<Control_panel>()), lift_cabin(std::make_shared<Lift_cabin>())
{
    // передача цели кабине
    QObject::connect(control_panel.get(), SIGNAL(set_target(int)), lift_cabin.get(), SLOT(cabin_set_target(int)));
    QObject::connect(lift_cabin.get(), SIGNAL(crossing_floor(int, direction)), control_panel.get(), SLOT(passed_floor(int)));
    QObject::connect(lift_cabin.get(), SIGNAL(cabin_stopped(int)), control_panel.get(), SLOT(achieved_floor(int)));
}

// получание сигнала от кнопки
void Lift::add_call(int floor)
{
    control_panel->set_new_target(floor);
}

