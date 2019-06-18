#ifndef SCENE_H
#define SCENE_H

#include "object/compositeobject.h"

#include <iostream>
#include <memory>
#include <vector>

class Scene
{
public:
    Scene() = default;
    ~Scene() = default;

    void add_model(const std::shared_ptr<Object>& model);
    void del_model(const size_t cnt);

    void add_cam(const std::shared_ptr<Object>& camera);
    void del_cam(const size_t cnt);

    std::shared_ptr<Object> get_model(const size_t cnt);
    std::shared_ptr<Object> get_cam(const size_t cnt);

    ObjectIter obj_beg();
    ObjectIter obj_end();
    ObjectIter model_cnt(const size_t cnt);
    ObjectIter cam_cnt(const size_t cnt);

private:
    CompositeObject object;
};

#endif // SCENE_H
