#include "delay.h"

Delay::Delay()
{

}

void Delay::delay_async(int milisec, std::function<void()> callback)
{
    QTimer::singleShot(milisec, callback);
}
