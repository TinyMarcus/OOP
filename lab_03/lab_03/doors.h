#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QLabel>
#include <QTimer>

#include "delay.h"

class Doors : public QObject
{
    Q_OBJECT

    enum door_state
    {
        door_is_opened,
        door_is_closed,
        door_is_opening,
        door_is_closing
    };

public:
    Doors();
    bool is_open();
    void update_state();

private:
    void set_state(door_state state);

    door_state st;
    Delay delay;

signals:
    void open();
    void close();
    void already_opened();
    void already_closed();
    void state_text_changed(QString state_text);

public slots:
    void opening();
    void closing();
    void opened();
    void closed();
};

#endif // DOORS_H
