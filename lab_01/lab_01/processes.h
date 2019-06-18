#ifndef PROCESSES_H
#define PROCESSES_H

#include "mesh.h"
#include "controller.h"
#include "graphics.h"
#include "model_transform.h"

error get_points_for_render(Vector4f* points, int& count, const mesh& model);
error render_process(mesh& model, controller& contr);
error load_model_process(mesh& model, controller& contr);
error save_model_process(mesh& model, controller& contr);
error translate_model_process(mesh& model, controller& contr);
error rotate_model_process(mesh& model, controller& contr);
error scale_model_process(mesh& model, controller& contr);

void release_mesh_controller(mesh& model, controller& contr);


#endif // PROCESSES_H
