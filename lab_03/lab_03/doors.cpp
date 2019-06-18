#include "doors.h"
#include "errors.h"
#include "delay.h"

#include <QDebug>

Doors::Doors()
{
    set_state(door_is_closed);

    connect(this, SIGNAL(open()), this, SLOT(opened()));
    connect(this, SIGNAL(close()), this, SLOT(closed()));
}

bool Doors::is_open()
{
    return st == door_is_opened;
}

void Doors::update_state()
{
    set_state(st);
}

void Doors::set_state(door_state state)
{
    st = state;

    QString state_text;

    switch (state)
    {
    case door_is_opened:
        state_text = "Открыты";
        break;
    case door_is_closed:
        state_text = "Закрыты";
        break;
    case door_is_opening:
        state_text = "Открываются";
        break;
    case door_is_closing:
        state_text = "Закрываются";
        break;
    }

    emit state_text_changed(state_text);
}

void Doors::opening()
{
    if ((st == door_is_opened) || (st == door_is_opening) || (st == door_is_closing))
        return;

    set_state(door_is_opening);
    delay.delay_async(1000, [=](void)
    {
        emit open();
    });

}

void Doors::closing()
{
    if ((st == door_is_closed) || (st == door_is_closing))
        return;

    set_state(door_is_closing);
    delay.delay_async(1000, [=](void)
    {
        emit close();
    });
}

void Doors::opened()
{
    set_state(door_is_opened);
    emit already_opened();
}

void Doors::closed()
{
    set_state(door_is_closed);
    emit already_closed();
}
