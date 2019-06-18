#include "processes.h"

/* Процесс загрузки модели (вызывается в точке входа) */
error load_model_process(mesh& model, controller& contr)
{
    error result = error::OK;
    mesh tmp;
    copy_mesh(tmp, model);
    result = load_mesh_from_file(model, contr.filename);
    if (result == error::OK)
    {
       release_mesh_controller(tmp, contr);
    }

    return result;
}

error render_process(mesh& model, controller& contr)
{
    get_points_for_render(&contr.projectedPoints, contr.pointsCount, model);
}

/* Сохранение в файл (обертка) */
error save_model_process(mesh& model, controller& contr)
{
    error result = error::OK;

    if (model.isLoaded)
    {
        result = save_mesh_to_file(model, contr.filename);
    }
    else
    {
        result = error::MeshNotLoaded;
    }

    return result;
}

/* Перемещение каркаса (обертка) */
error translate_model_process(mesh& model, controller& contr)
{
    error result = error::OK;

    if (model.isLoaded)
    {
        Vector3f translate = { contr.userInput.dx,
                               contr.userInput.dy,
                               contr.userInput.dz };

        translate_model(model, translate);
    }
    else
    {
        result = error::MeshNotLoaded;
    }

    return result;
}

/* Вращение каркаса (обертка) */
error rotate_model_process(mesh& model, controller& contr)
{
    error result = error::OK;

    if (model.isLoaded)
    {
        Vector3f rotate = { contr.userInput.rotateX,
                            contr.userInput.rotateY,
                            contr.userInput.rotateZ };

        rotate_model(model, rotate);
    }
    else
    {
        result = error::MeshNotLoaded;
    }

    return result;
}

/* Масштабирование каркаса (обертка) */
error scale_model_process(mesh& model, controller& contr)
{
    error result = error::OK;

    if (model.isLoaded)
    {
        Vector3f scale = { contr.userInput.scaleX,
                           contr.userInput.scaleY,
                           contr.userInput.scaleZ };

        scale_model(model, scale);
    }
    else
    {
        result = error::MeshNotLoaded;
    }

    return result;
}

/* Очистка всех данных, очистка памяти */
void release_mesh_controller(mesh& model, controller& contr)
{
    delete_mesh(model);
    release_controller(contr);
}
