#include "graphics.h"

/* Рисование линии по двум точкам */
void draw_line(QGraphicsScene* scene, const Vector2i& p1, const Vector2i& p2)
{
    scene->addLine(p1.x, p1.y, p2.x, p2.y, QPen(Qt::black));
}

/* Подготовка точек и рисование линии */
void render_projected_points(QGraphicsScene* scene, const Vector4f* points, int count, int scrWidth, int scrHeight)
{
    for (int i = 0; i < count; i += 2)
    {
        Vector2i lineBegin = convert_to_raster(points[i], scrWidth, scrHeight);
        Vector2i lineEnd = convert_to_raster(points[i + 1], scrWidth, scrHeight);

        draw_line(scene, lineBegin, lineEnd);
    }
}

/* Перевод координат точек в пиксели на экране */
Vector2i convert_to_raster(const Vector4f& p, int scrWidth, int scrHeight)
{
    Vector2i res;
    res.x = (int)(p.x * (scrWidth - 1) / 2 + (scrWidth - 1) / 2);
    res.y = (int)(p.y * (scrHeight - 1) / 2 + (scrHeight - 1) / 2);

    return res;
}

/* Проецирование точек */
Vector4f point_projection(const Vector4f& p, const Matrix4f& projection_matrix)
{
    Vector4f res = multiply_vector_by_matrix(p, projection_matrix);

    res.x /= res.z;
    res.y /= res.z;

    return res;
}
