#include "camera.h"

Camera::Camera() : move_param(3, 0), scale_param(3, 1), rotate_param(3, 0) {}

double Camera::move_get_x() const {return move_param[0];}
double Camera::move_get_y() const {return move_param[1];}
double Camera::move_get_z() const {return move_param[2];}

double Camera::scale_get_x() const {return scale_param[0];}
double Camera::scale_get_y() const {return scale_param[1];}
double Camera::scale_get_z() const {return scale_param[2];}

double Camera::rotate_get_x() const {return rotate_param[0];}
double Camera::rotate_get_y() const {return rotate_param[1];}
double Camera::rotate_get_z() const {return rotate_param[2];}


void Camera::move(const double x, const double y, const double z)
{
    move_param[0] = move_param[0] + x;
    move_param[1] = move_param[1] + y;
    move_param[2] = move_param[2] + z;
}

void Camera::scale(const double x, const double y, const double z)
{
    scale_param[0] = scale_param[0] * x;
    scale_param[1] = scale_param[1] * y;
    scale_param[2] = scale_param[2] * z;
}

void Camera::rotate(const double x, const double y, const double z)
{
    rotate_param[0] = rotate_param[0] + x;
    rotate_param[1] = rotate_param[1] + y;
    rotate_param[2] = rotate_param[2] + z;
}
