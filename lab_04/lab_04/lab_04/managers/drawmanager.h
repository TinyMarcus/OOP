#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "ui/drawer.h"
#include "object/compositeobject.h"
#include "exceptions/drawerexception.h"

class DrawManager
{
public:
    DrawManager() = default;
    ~DrawManager() = default;

    void draw_model(BaseDrawer &drw, const ObjectIter& beg, const ObjectIter& end, std::shared_ptr<Object> obj);
private:
    static constexpr double coeff3D = 0.5;
    double get_x(const double x, const double z) const;
    double get_y(const double y, const double z) const;
};

#endif // DRAWMANAGER_H
