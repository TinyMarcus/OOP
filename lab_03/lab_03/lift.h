#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QTextEdit>
#include <QTimer>
#include <QQueue>
#include <QLabel>

#include "cage.h"
#include "delay.h"

using namespace std;

class Lift : public QObject
{
    Q_OBJECT
    enum lift_state
    {
        lift_is_busy,
        lift_is_free
    };

public:
    Lift();
    void update_state();

private:
    void set_state(lift_state state);
    Cage cabin;
    std::vector<int> queue;
    lift_state state;
    Delay delay;

signals:
    void move_up();
    void move_down();
    void open_doors();
    void state_text_changed(QString state_text);
    void cage_state_text_changed(QString state_text);
    void doors_state_text_changed(QString state_text);
    void floor_changed(int floor);

public slots:
    void floor_btn_pressed(int floor);
    void cage_arrived();
};

#endif // LIFT_H
