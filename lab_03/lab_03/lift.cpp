#include "lift.h"
#include "errors.h"
#include <stdio.h>
#include "delay.h"
#include <QDebug>

using namespace std;

Lift::Lift()
{
    set_state(lift_is_free);

    connect(&cabin, SIGNAL(arrived()), this, SLOT(cage_arrived()));
    connect(this, SIGNAL(move_up()), &cabin, SLOT(move_up()));
    connect(this, SIGNAL(move_down()), &cabin, SLOT(move_down()));
    connect(this, SIGNAL(open_doors()), &cabin, SLOT(open_doors()));
    connect(&cabin, SIGNAL(state_text_changed(QString)), this, SIGNAL(cage_state_text_changed(QString)));
    connect(&cabin, SIGNAL(doors_state_text_changed(QString)), this, SIGNAL(doors_state_text_changed(QString)));
}

void Lift::update_state()
{
    set_state(state);
    cabin.update_state();
}

void Lift::set_state(lift_state state)
{
    this->state = state;

    QString state_text;

    switch (state)
    {
    case lift_is_busy:
        state_text = "Занят";
        break;
    case lift_is_free:
        state_text = "Свободен";
        break;
    }

    emit state_text_changed(state_text);
}

void Lift::floor_btn_pressed(int floor)
{
    if (std::find(queue.begin(), queue.end(), floor) == queue.end())
    {
        queue.push_back(floor);
    }

    if (state == lift_is_free)
    {
        set_state(lift_is_busy);

        if (cabin.get_floor() == floor)
        {
            emit open_doors();
            return;
        }

        bool is_move_up = cabin.get_floor() < floor;

        if (is_move_up)
        {
            emit move_up();
        }
        else
        {
            emit move_down();
        }
    }
}

void Lift::cage_arrived()
{
    emit floor_changed(cabin.get_floor());

    qDebug() << "Этаж: " << queue;

    if (std::find(queue.begin(), queue.end(), cabin.get_floor()) != queue.end())
    {
        delay.delay_async(1000, [=](void)
        {
            emit open_doors();
            queue.erase(std::remove(queue.begin(), queue.end(), cabin.get_floor()), queue.end());
        });
    }
    else if (queue.size() == 0)
    {
        set_state(lift_is_free);
    }
    else
    {
        set_state(lift_is_busy);

        bool is_move_up = cabin.get_floor() < queue.front();

        if (is_move_up)
        {
            emit move_up();
        }
        else
        {
            emit move_down();
        }
    }
}
