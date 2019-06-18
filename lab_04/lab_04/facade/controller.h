#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "actions/action.h"
#include "facade.h"

class Controller
{
public:
    Controller()
    {
        facade = std::make_shared<Facade>();
    }

    ~Controller() = default;

    void make_action(BaseAction& action)
    {
        action.make(facade);
    }
private:
    std::shared_ptr<Facade> facade;
};

#endif // CONTROLLER_H
