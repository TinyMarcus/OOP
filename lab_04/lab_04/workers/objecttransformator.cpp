#include "objecttransformator.h"

ModelTransformator::ModelTransformator(BaseTransformations &trans) : trans(trans) {}

void ModelTransformator::transform(std::shared_ptr<Object> obj)
{
    double x = trans.get_x();
    double y = trans.get_y();
    double z = trans.get_z();

    std::shared_ptr<Model> model = std::static_pointer_cast<Model>(obj);

    if (trans.is_moving())
        model->move(x, y, z);
    if (trans.is_scaling())
        model->scale(x, y, z);
    if (trans.is_rotating())
        model->rotate(x, y, z);
}

CameraTransformator::CameraTransformator(BaseTransformations &trans) : trans(trans) {}

void CameraTransformator::transform(std::shared_ptr<Object> obj)
{
    double x = trans.get_x();
    double y = trans.get_y();
    double z = trans.get_z();

    std::shared_ptr<Camera> camera = std::static_pointer_cast<Camera>(obj);

    if (trans.is_moving())
        camera->move(x, y, z);
    if (trans.is_scaling())
        camera->scale(x, y, z);
    if (trans.is_rotating())
        camera->rotate(x, y, z);
}
