#include "facade.h"

void Facade::add_model(BaseIO &io, BaseBuilder &build)
{
    this->scene.add_model(io_manager.io_model(io, build));
}

void Facade::del_model(const size_t cnt)
{
    this->scene.del_model(cnt);
}

void Facade::add_cam()
{
    Camera* cam_ptr = new Camera();
    std::shared_ptr<Object> cam(cam_ptr);
    this->scene.add_cam(cam);
}

void Facade::del_cam(const size_t cnt)
{
    this->scene.del_cam(cnt);
}

void Facade::draw(BaseDrawer &drw, const size_t cam_cnt)
{
    ObjectIter beg = this->scene.obj_beg();
    ObjectIter end = this->scene.obj_end();
    this->draw_manager.draw_model(drw, beg, end, this->scene.get_cam(cam_cnt));
}

void Facade::transform_model(BaseTransformator &trans, const size_t model_cnt)
{
    ObjectIter beg = (model_cnt == -1) ? this->scene.obj_beg() : \
                                         this->scene.model_cnt(model_cnt);
    ObjectIter end = (model_cnt == -1) ? this->scene.obj_end() : \
                                         this->scene.model_cnt(model_cnt + 1);

    this->model_manager.transform(trans, beg, end);
}

void Facade::transform_cam(BaseTransformator &trans, const size_t cam_cnt)
{
    ObjectIter beg = this->scene.cam_cnt(cam_cnt);
    ObjectIter end = this->scene.cam_cnt(cam_cnt + 1);
    this->cam_manager.transform(trans, beg, end);
}
