#ifndef FACADE_H
#define FACADE_H

#include "managers/drawmanager.h"
#include "managers/iomanager.h"
#include "managers/objectmanager.h"
#include "scene/scene.h"

class Facade
{
public:
    Facade() = default;
    ~Facade() = default;

    void add_model(BaseIO& io, BaseBuilder& build);
    void del_model(const size_t cnt);

    void add_cam();
    void del_cam(const size_t cnt);

    void transform_model(BaseTransformator& trans, const size_t model_cnt);
    void transform_cam(BaseTransformator& trans, const size_t cam_cnt);

    void draw(BaseDrawer& drw, const size_t cam_cnt);
private:
    Scene scene;
    IOManager io_manager;
    DrawManager draw_manager;
    ModelManager model_manager;
    CameraManager cam_manager;
};

#endif // FACADE_H
