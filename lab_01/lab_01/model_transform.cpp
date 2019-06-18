#include "model_transform.h"

/* Вращение каркаса */
void rotate_model(mesh& model, const Vector3f& rotateXYZ)
{
    Matrix4f rX = createRotXMatrix(rotateXYZ.x);
    Matrix4f rY = createRotYMatrix(rotateXYZ.y);
    Matrix4f rZ = createRotZMatrix(rotateXYZ.z);
    Matrix4f rM;

    rM = multiply_matrices(rX, rY);
    rM = multiply_matrices(rM, rZ);

    for (int i = 0; i < model.verticesCount; i++)
    {
        model.vertices[i] = multiply_vector_by_matrix(model.vertices[i], rM);
    }
}

/* Перемещение каркаса */
void translate_model(mesh& model, const Vector3f& translateXYZ)
{
    Matrix4f transM = create_translate_matrix(translateXYZ);
    for (int i = 0; i < model.verticesCount; i++)
    {
        model.vertices[i] = multiply_vector_by_matrix(model.vertices[i], transM);
    }
}

/* Масштабирование каркаса */
void scale_model(mesh& model, const Vector3f& scaleXYZ)
{
    Matrix4f scaleM = create_scale_matrix(scaleXYZ);
    for (int i = 0; i < model.verticesCount; i++)
    {
        model.vertices[i] = multiply_vector_by_matrix(model.vertices[i], scaleM);
    }
}

/* Получение точек для отрисовки */
void get_points_for_render(Vector4f** points, int& count, const mesh& model)
{
    count = model.indicesCount;

    if (!*points)
        *points = new Vector4f[count];

    Vector4f* ptrPoints = *points;

    const Matrix4f projection = create_projection_matrix(0.001, 1000.0, 4.0 / 3.0, 60.0);
    for (int i = 0; i < count; i += 2)
    {
        Vector4f lineStart, lineEnd;
        int idxStart = model.indices[i];
        int idxEnd = model.indices[i + 1];

        lineStart = model.vertices[idxStart];
        lineEnd = model.vertices[idxEnd];

        lineStart = point_projection(lineStart, projection);
        lineEnd = point_projection(lineEnd, projection);

        ptrPoints[i] = lineStart;
        ptrPoints[i + 1] = lineEnd;
    }
}
