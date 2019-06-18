#ifndef MATHS_H
#define MATHS_H

#define _USE_MATH_DEFINES
#include <cmath>

struct Vector3f
{
    double x;
    double y;
    double z;
};

struct Vector4f
{
    double x;
    double y;
    double z;
    double w;
};

struct Vector2i
{
    int x;
    int y;
};


struct Matrix4f
{
    double value[4][4];
};

inline double to_radians(double degrees)
{
    return (double)(degrees * M_PI / 180);
}

Vector3f add_vectors(const Vector3f& left, const Vector3f& right);
Vector4f add_vectors(const Vector4f& left, const Vector4f& right);
Vector2i add_vectors(const Vector2i& left, const Vector2i& right);

Vector3f sub_vectors(const Vector3f& left, const Vector3f& right);
Vector4f sub_vectors(const Vector4f& left, const Vector4f& right);
Vector2i sub_vectors(const Vector2i& left, const Vector2i& right);

Matrix4f init_matrix(double diagonal);
Matrix4f createRotXMatrix(double angle);
Matrix4f createRotYMatrix(double angle);
Matrix4f createRotZMatrix(double angle);
Matrix4f create_scale_matrix(const Vector3f& scale);
Matrix4f create_translate_matrix(const Vector3f& translate);
Matrix4f create_projection_matrix(double zNear, double zFar, double aspect, double fov);

Vector4f multiply_vector_by_matrix(const Vector4f& v, const Matrix4f& m);
Matrix4f multiply_matrices(const Matrix4f& left, const Matrix4f& right);

Vector4f multiply_vector_by_scalar(const Vector4f& v, double k);
Vector3f multiply_vector_by_scalar(const Vector3f& v, double k);
Vector2i multiply_vector_by_scalar(const Vector2i& v, double k);

#endif // MATHS_H
