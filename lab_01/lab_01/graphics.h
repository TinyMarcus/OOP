#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGraphicsScene>
#include "maths.h"
#include "mesh.h"

void draw_line(QGraphicsScene* scene, const Vector2i& p1, const Vector2i& p2);
void render_projected_points(QGraphicsScene* scene, const Vector4f* points, int count, int scrWidth, int scrHeight);
Vector2i convert_to_raster(const Vector4f& p, int scrWidth, int scrHeight);
Vector4f point_projection(const Vector4f& p, const Matrix4f& projection_matrix);

#endif // GRAPHICS_H
