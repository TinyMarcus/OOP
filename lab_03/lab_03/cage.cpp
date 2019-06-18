#include "cage.h"
#include "errors.h"
#include <stdio.h>
#include "delay.h"
#include <QDebug>

Cage::Cage()
{
    st = cage_is_waiting_closed;
    next_st = cage_is_waiting_closed;
    floor = 1;

    connect(&door, SIGNAL(already_opened()), this, SLOT(doors_are_opened()));
    connect(&door, SIGNAL(already_closed()), this, SLOT(doors_are_closed()));
    connect(&door, SIGNAL(state_text_changed(QString)), this, SIGNAL(doors_state_text_changed(QString)));
    connect(this, SIGNAL(start_opening()), &door, SLOT(opening()));
    connect(this, SIGNAL(start_closing()), &door, SLOT(closing()));
}

void Cage::set_state(cage_state state)
{
    st = state;

    QString state_text;

    switch (state)
    {
    case cage_is_going_up:
        state_text = "Едет вверх";
        break;
    case cage_is_going_down:
        state_text = "Едет вниз";
        break;
    case cage_is_waiting_opened:
        state_text = "Ожидает с открытыми дверьми";
        break;
    case cage_is_waiting_closed:
        state_text = "Ожидает с закрытыми дверьми";
        break;
    }

    emit state_text_changed(state_text);
}

int Cage::get_floor()
{
    return floor;
}

void Cage::update_state()
{
    set_state(st);
    door.update_state();
}

void Cage::open_doors()
{
    next_st = cage_is_waiting_closed;
    set_state(cage_is_waiting_closed);

    delay.delay_async(1000, [=](void)
    {
        //set_state(cage_is_opened);
        emit start_opening();
    });
}

void Cage::doors_are_opened()
{
    set_state(cage_is_waiting_opened);

    delay.delay_async(2000, [=](void)
    {
        //set_state(cage_is_closed);
        emit start_closing();
    });
}

void Cage::doors_are_closed()
{
    set_state(cage_is_waiting_closed);

    delay.delay_async(500, [=](void)
    {
        set_state(next_st);
        emit arrived();
    });
}

void Cage::move_up()
{
    if (door.is_open())
    {
        next_st = cage_is_going_up;
        emit start_closing();
        //set_state(cage_is_closed);
        return;
    }

    delay.delay_async(1000, [=](void)
    {
        set_state(cage_is_going_up);

        delay.delay_async(1000, [=](void)
        {
            floor++;
            emit arrived();
        });
    });
}

void Cage::move_down()
{
    if (door.is_open())
    {
        next_st = cage_is_going_down;        
        emit start_closing();
        //set_state(cage_is_closed);
        return;
    }

    delay.delay_async(1000, [=](void)
    {
        set_state(cage_is_going_down);

        delay.delay_async(1000, [=](void)
        {
            floor--;
            emit arrived();
        });
    });
}
