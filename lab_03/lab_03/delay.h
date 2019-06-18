#ifndef DELAY_H
#define DELAY_H

#include <QTime>
#include <QTimer>
#include <QCoreApplication>
#include <functional>

class Delay : public QObject
{
    Q_OBJECT

public:
    Delay();
    void delay_async(int milisec, std::function<void(void)> callback);
};

#endif // DELAY_H
