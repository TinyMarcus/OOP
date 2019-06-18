#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include <vector>

class BaseTransformations
{
public:
    BaseTransformations(const double x, const double y, const double z) : x(x), y(y), z(z) {}
    virtual ~BaseTransformations() = default;

    virtual bool is_moving() = 0;
    virtual bool is_scaling() = 0;
    virtual bool is_rotating() = 0;

    double get_x() {return x;}
    double get_y() {return y;}
    double get_z() {return z;}

protected:
    double x, y, z;
};

class Moving : public BaseTransformations
{
public:
    Moving(const double shX, const double shY, const double shZ) : BaseTransformations(shX, shY, shZ) {}
    ~Moving() = default;

    bool is_moving() {return true;}
    bool is_scaling() {return false;}
    bool is_rotating() {return false;}
};

class Scaling : public BaseTransformations
{
public:
    Scaling(const double scX, const double scY, const double scZ) : BaseTransformations(scX, scY, scZ) {}
    ~Scaling() = default;

    bool is_moving() {return false;}
    bool is_scaling() {return true;}
    bool is_rotating() {return false;}
};

class Rotating : public BaseTransformations
{
public:
    Rotating(const double rtX, const double rtY, const double rtZ) : BaseTransformations(rtX, rtY, rtZ) {}
    ~Rotating() = default;

    bool is_moving() {return false;}
    bool is_scaling() {return false;}
    bool is_rotating() {return true;}
};

#endif // TRANSFORMATIONS_H
