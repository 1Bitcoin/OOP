#include "cabin.h"

Lift_cabin::Lift_cabin(QObject *parent) : QObject(parent), doors(std::make_shared<Lift_doors>()), crossing_floor_timer(std::make_shared<QTimer>())
{
    current_direction = STILL; // напр
    current_floor = 1; // нач. этаж
    current_state = STAY; // сост

    crossing_floor_timer->setSingleShot(true);

    QObject::connect(this, SIGNAL(reached_target(int)), this, SLOT(cabin_stopping()));
    QObject::connect(this, SIGNAL(cabin_stopped(int)), doors.get(), SLOT(start_openning()));
    QObject::connect(crossing_floor_timer.get(), SIGNAL(timeout()), this, SLOT(cabin_moving()));
    QObject::connect(this, SIGNAL(pre_moving()), doors.get(), SLOT(start_closing()));
    QObject::connect(doors.get(), SIGNAL(closed_doors()), this, SLOT(cabin_moving()));
}

void Lift_cabin::cabin_moving()
{
    if (current_state == GOT_TARGET)
    {
        current_state = MOVING;
        crossing_floor_timer->start(CROSSING_FLOOR);
    }
    else if (current_state == MOVING)
    {
        current_floor += (current_direction == UP ? 1 : -1);
        if (current_floor == target)
            emit reached_target(current_floor);
        else
        {
            emit crossing_floor(current_floor, current_direction);
            crossing_floor_timer->start(CROSSING_FLOOR);
        }
    }
}

void Lift_cabin::cabin_stopping()
{
    current_state = STAY;
    qDebug() << "Лифт остановился на этаже " << QString::number(current_floor) << ".";
    emit cabin_stopped(current_floor);
}

void Lift_cabin::cabin_set_target(int floor)
{
    current_state = GOT_TARGET;
    target = floor;

    if (current_floor == target)
    {
        emit reached_target(floor);
    }
    else
    {
        current_direction = (current_floor > target) ? DOWN : UP;
        emit pre_moving();
    }
}
