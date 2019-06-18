#include "controller.h"

/* Создание */
controller create_controller()
{
    controller contr;
    contr.userInput.scaleX = 1.0;
    contr.userInput.scaleY = 1.0;
    contr.userInput.scaleZ = 1.0;
    contr.userInput.rotateX = 0;
    contr.userInput.rotateY = 0;
    contr.userInput.rotateZ = 0;
    contr.userInput.dx = 0;
    contr.userInput.dy = 0;
    contr.userInput.dz = 0;
    contr.pointsCount = 0;
    contr.projectedPoints = nullptr;

    return contr;
}

/* Очистка */
void release_controller(controller& contr)
{
    if (contr.projectedPoints)
    {
        contr.pointsCount = 0;
        delete[] contr.projectedPoints;
    }
}
