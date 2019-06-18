#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"
#include <vector>

class Camera : public InvisibleObject
{
public:
    Camera();
    ~Camera() = default;

    double move_get_x() const;
    double move_get_y() const;
    double move_get_z() const;

    double scale_get_x() const;
    double scale_get_y() const;
    double scale_get_z() const;

    double rotate_get_x() const;
    double rotate_get_y() const;
    double rotate_get_z() const;

    void move(const double x, const double y, const double z);
    void scale(const double x, const double y, const double z);
    void rotate(const double x, const double y, const double z);
private:
    std::vector<double> move_param;
    std::vector<double> scale_param;
    std::vector<double> rotate_param;
};

#endif // CAMERA_H
