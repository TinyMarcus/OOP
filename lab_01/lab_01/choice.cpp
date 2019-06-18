#include "choice.h"

/* Точка входа */
error choice(controller& contr, UserAction action)
{
    error result = error::OK;
    static mesh model = init_mesh();

    switch (action)
    {
    case(LoadModel):
        result = load_model_process(model, contr);
        break;
    case(SaveModel):
        result = save_model_process(model, contr);
        break;
    case(Translate):
        result = translate_model_process(model, contr);
        break;
    case(Scale):
        result = scale_model_process(model, contr);
        break;
    case(Rotate):
        result = rotate_model_process(model, contr);
        break;
    case(RenderModel):
        result = render_process(model, contr);
        break;
    case(Quit):
        release_mesh_controller(model, contr);
        break;
    default:
        result = error::UnknownAction;
        break;
    }

    return result;
}
