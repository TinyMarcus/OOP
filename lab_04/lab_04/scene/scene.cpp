#include "scene.h"

void Scene::add_model(const std::shared_ptr<Object>& object)
{
    this->object.add_model(object);
}

void Scene::del_model(const size_t index)
{
    this->object.del_model(index);
}

void Scene::add_cam(const std::shared_ptr<Object>& object)
{
    this->object.add_cam(object);
}

void Scene::del_cam(const size_t index)
{
    this->object.del_cam(index);
}

std::shared_ptr<Object> Scene::get_model(const size_t index)
{
    return this->object.get_model(index);
}

std::shared_ptr<Object> Scene::get_cam(const size_t index)
{
    return this->object.get_cam(index);
}

ObjectIter Scene::obj_beg()
{
    return this->object.obj_beg();
}

ObjectIter Scene::obj_end()
{
    return this->object.obj_end();
}

ObjectIter Scene::model_cnt(const size_t cnt)
{
    return this->object.model_cnt(cnt);
}

ObjectIter Scene::cam_cnt(const size_t cnt)
{
    return this->object.cam_cnt(cnt);
}
