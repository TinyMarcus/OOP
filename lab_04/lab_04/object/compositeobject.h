#ifndef COMPOSITEOBJECT_H
#define COMPOSITEOBJECT_H

#include "model.h"
#include "camera.h"
#include "iterator/iterator.h"
#include "exceptions/objectexception.h"

#include <vector>

class CompositeObject : public Object
{
public:
    CompositeObject();
    ~CompositeObject() = default;

    void add_model(std::shared_ptr<Object> obj);
    void del_model(const size_t cnt);

    void add_cam(std::shared_ptr<Object> obj);
    void del_cam(const size_t cnt);

    std::shared_ptr<Object> get_model(const size_t cnt);
    std::shared_ptr<Object> get_cam(const size_t cnt);

    ObjectIter obj_beg();
    ObjectIter obj_end();
    ObjectIter model_cnt(const size_t cnt);
    ObjectIter cam_cnt(const size_t cnt);

    bool is_visible() override { return true; }
private:
    std::vector<std::shared_ptr<Object>> objects;
    size_t model_num;
    size_t cam_num;
};

#endif // COMPOSITEOBJECT_H
