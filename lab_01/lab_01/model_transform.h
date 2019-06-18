#ifndef MODEL_TRANSFORM_H
#define MODEL_TRANSFORM_H

#include "mesh.h"
#include "graphics.h"

void rotate_model(mesh& model, const Vector3f& rotateXYZ);
void translate_model(mesh& model, const Vector3f& translateXYZ);
void scale_model(mesh& model, const Vector3f& scaleXYZ);
void get_points_for_render(Vector4f** points, int& count, const mesh& model);

#endif // MODEL_TRANSFORM_H
