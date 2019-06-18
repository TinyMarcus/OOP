#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <strings.h>
#include "errors.h"
#include "maths.h"

#define MAX_STRING 256

enum UserAction
{
    Translate = 0,
    Rotate,
    Scale,
    LoadModel,
    SaveModel,
    RenderModel,
    Quit
};

enum ModelResponseAction
{
    Render,
    ShowErrorMessage
};

struct UserInput
{
    double dx;
    double dy;
    double dz;
    double rotateX;
    double rotateY;
    double rotateZ;
    double scaleX;
    double scaleY;
    double scaleZ;
};

struct controller
{
    char *filename;
    UserInput userInput;
    Vector4f* projectedPoints;
    int pointsCount;
};

controller create_controller();
void release_controller(controller& contr);

#endif // CONTROLLER_H
