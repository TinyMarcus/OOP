#ifndef CAGE_H
#define CAGE_H

#include <QObject>
#include <QTextEdit>
#include <QTimer>
#include <QQueue>
#include <QLabel>

#include "delay.h"
#include "doors.h"

class Cage : public QObject
{
    Q_OBJECT
    enum cage_state
    {
        cage_is_going_up,
        cage_is_going_down,
        cage_is_waiting_opened,
        cage_is_waiting_closed,
    };

public:
    Cage();

    int get_floor();
    void update_state();

private:
    void set_state(cage_state state);
    Doors door;
    cage_state st;
    cage_state next_st;
    int floor;
    Delay delay;

signals:
    void start_opening();
    void start_closing();
    void arrived();
    void state_text_changed(QString state_text);
    void doors_state_text_changed(QString state_text);

public slots:
    void move_up();
    void move_down();
    void open_doors();
    void doors_are_opened();
    void doors_are_closed();
};

#endif // CAGE_H
