#include "maths.h"

/* Сложение векторов */
Vector3f add_vectors(const Vector3f& left, const Vector3f& right)
{
    Vector3f result;
    result.x = left.x + right.x;
    result.y = left.y + right.y;
    result.z = left.z + right.z;

    return result;
}

/* Сложение векторов */
Vector4f add_vectors(const Vector4f& left, const Vector4f& right)
{
    Vector4f result;
    result.x = left.x + right.x;
    result.y = left.y + right.y;
    result.z = left.z + right.z;
    result.w = left.w + right.w;

    return result;
}

/* Сложение векторов */
Vector2i add_vectors(const Vector2i& left, const Vector2i& right)
{
    Vector2i result;
    result.x = left.x + right.x;
    result.y = left.y + right.y;

    return result;
}

/* Вычитание векторов */
Vector3f sub_vectors(const Vector3f& left, const Vector3f& right)
{
    Vector3f result;
    result.x = left.x - right.x;
    result.y = left.y - right.y;
    result.z = left.z - right.z;

    return result;
}

/* Вычитание векторов */
Vector4f sub_vectors(const Vector4f& left, const Vector4f& right)
{
    Vector4f result;
    result.x = left.x - right.x;
    result.y = left.y - right.y;
    result.z = left.z - right.z;
    result.w = left.w - right.w;

    return result;
}

/* Вычитание векторов */
Vector2i sub_vectors(const Vector2i& left, const Vector2i& right)
{
    Vector2i result;
    result.x = left.x - right.x;
    result.y = left.y - right.y;

    return result;
}

/* Инициализация матрицы */
Matrix4f init_matrix(double diagonal)
{
    Matrix4f result;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result.value[i][j] = 0;
        }
    }

    result.value[0][0] = diagonal;
    result.value[1][1] = diagonal;
    result.value[2][2] = diagonal;
    result.value[3][3] = diagonal;

    return result;
}

/* Создание матрицы вращения по X */
Matrix4f createRotXMatrix(double angle)
{
    angle = to_radians(angle);
    Matrix4f result = init_matrix(1.0);

    result.value[1][1] =  cos(angle);
    result.value[1][2] =  sin(angle);
    result.value[2][1] = -sin(angle);
    result.value[2][2] =  cos(angle);

    return result;
}

/* Создание матрицы вращения по Y */
Matrix4f createRotYMatrix(double angle)
{
    angle = to_radians(angle);
    Matrix4f result = init_matrix(1.0);

    result.value[0][0] =  cos(angle);
    result.value[0][2] = -sin(angle);
    result.value[2][0] =  sin(angle);
    result.value[2][2] =  cos(angle);

    return result;
}

/* Создание матрицы вращения по Z */
Matrix4f createRotZMatrix(double angle)
{
    angle = to_radians(angle);
    Matrix4f result = init_matrix(1.0);

    result.value[0][0] =  cos(angle);
    result.value[0][1] =  sin(angle);
    result.value[1][0] = -sin(angle);
    result.value[1][1] =  cos(angle);

    return result;
}

/* Создание матрицы для масштабирования */
Matrix4f create_scale_matrix(const Vector3f& scale)
{
    Matrix4f result = init_matrix(1.0);
    result.value[0][0] = scale.x;
    result.value[1][1] = scale.y;
    result.value[2][2] = scale.z;

    return result;
}

/* Создание матрицы переноса */
Matrix4f create_translate_matrix(const Vector3f& translate)
{
    Matrix4f result = init_matrix(1.0);
    result.value[3][0] = translate.x;
    result.value[3][1] = translate.y;
    result.value[3][2] = translate.z;

    return result;
}

/* Создание матрицы с точками проецирования */
Matrix4f create_projection_matrix(double zNear, double zFar, double aspect, double fov)
{
    Matrix4f result = init_matrix(1.0);

    const double zRange = zNear - zFar;
    const double tanHalfFOV = tanf(to_radians(fov / 2.0));

    result.value[0][0] = 1.0 / (tanHalfFOV * aspect);
    result.value[0][1] = 0.0;
    result.value[0][2] = 0.0;
    result.value[0][3] = 0.0;

    result.value[1][0] = 0.0;
    result.value[1][1] = 1.0 / tanHalfFOV;
    result.value[1][2] = 0.0;
    result.value[1][3] = 0.0;

    result.value[2][0] = 0.0;
    result.value[2][1] = 0.0;
    result.value[2][2] = (-zNear - zFar) / zRange;
    result.value[2][3] = 2.0 * zFar * zNear / zRange;

    result.value[3][0] = 0.0;
    result.value[3][1] = 0.0;
    result.value[3][2] = 1.0;
    result.value[3][3] = 0.0;

    return result;
}

/* Умножение матрицы на вектор */
Vector4f multiply_vector_by_matrix(const Vector4f& v, const Matrix4f& m)
{

    Vector4f result;
    result.x = v.x * m.value[0][0] + v.y * m.value[1][0] +
        v.z * m.value[2][0] + v.w * m.value[3][0];

    result.y = v.x * m.value[0][1] + v.y * m.value[1][1] +
        v.z * m.value[2][1] + v.w * m.value[3][1];

    result.z = v.x * m.value[0][2] + v.y * m.value[1][2] +
        v.z * m.value[2][2] + v.w * m.value[3][2];

    result.w = v.x * m.value[0][3] + v.y * m.value[1][3] +
        v.z * m.value[2][3] + v.w * m.value[3][3];

    return result;
}

/* Перемножение матриц */
Matrix4f multiply_matrices(const Matrix4f& left, const Matrix4f& right)
{
    Matrix4f result = init_matrix(1.0);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            double sum = 0.0;
            for (int e = 0; e < 4; e++)
            {
                sum += left.value[i][e] * right.value[e][j];
            }
            result.value[i][j] = sum;
        }
    }

    return result;
}

/* Умножение вектора на скалярное значение */
Vector4f multiply_vector_by_scalar(const Vector4f& v, double k)
{
    Vector4f result;
    result.x = v.x * k;
    result.y = v.y * k;
    result.z = v.z * k;
    result.w = v.w * k;

    return result;
}

/* Умножение вектора на скалярное значение */
Vector3f multiply_vector_by_scalar(const Vector3f& v, double k)
{
    Vector3f result;
    result.x = v.x * k;
    result.y = v.y * k;
    result.z = v.z * k;

    return result;
}

/* Умножение вектора на скалярное значение */
Vector2i multiply_vector_by_scalar(const Vector2i& v, double k)
{
    Vector2i result;
    result.x = v.x * k;
    result.y = v.y * k;

    return result;
}

