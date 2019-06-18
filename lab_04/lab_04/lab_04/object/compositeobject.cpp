#include "compositeobject.h"

CompositeObject::CompositeObject() : model_num(0), cam_num(0) {}

void CompositeObject::add_model(std::shared_ptr<Object> object)
{
    objects.push_back(std::static_pointer_cast<Model>(object));
    ++model_num;
}

void CompositeObject::del_model(const size_t cnt)
{
    size_t count = 0;
    size_t i = 0;

    for (; i < objects.size(); ++i)
    {
        if (objects[i]->is_visible())
            ++count;
        if (count == cnt + 1)
            break;
    }

    if (count != cnt + 1)
    {
        throw ObjectOutOfRangeException(": del_model");
    }
    else
    {
        objects.erase(objects.begin() + i);
        --model_num;
    }
}

void CompositeObject::add_cam(std::shared_ptr<Object> obj)
{
    objects.push_back(std::static_pointer_cast<Camera>(obj));
    ++cam_num;
}


void CompositeObject::del_cam(const size_t cnt)
{
    size_t count = 0;
    size_t i = 0;

    for (; i < objects.size(); ++i)
    {
        if (!objects[i]->is_visible())
            ++count;
        if (count == cnt + 1)
            break;
    }

    if (count != cnt + 1)
    {
        throw ObjectOutOfRangeException(": del_cam");
    }
    else
    {
        objects.erase(objects.begin() + i);
        --model_num;
    }
}

std::shared_ptr<Object> CompositeObject::get_model(const size_t cnt)
{
    size_t count = 0;
    size_t i = 0;

    for (; i < objects.size(); ++i)
    {
        if (objects[i]->is_visible())
            ++count;
        if (count == cnt + 1)
            break;
    }

    if (count != cnt + 1)
        throw ObjectOutOfRangeException(": get_model");
    else
        return objects[i];
}

std::shared_ptr<Object> CompositeObject::get_cam(const size_t cnt)
{
    size_t count = 0;
    size_t i = 0;

    for (; i < objects.size(); ++i)
    {
        if (!objects[i]->is_visible())
            ++count;
        if (count == cnt + 1)
            break;
    }

    if (count != cnt + 1)
        throw ObjectOutOfRangeException(": get_cam");
    else
        return objects[i];
}

ObjectIter CompositeObject::obj_beg()
{
    return objects.begin();
}

ObjectIter CompositeObject::obj_end()
{
    return objects.end();
}

ObjectIter CompositeObject::model_cnt(const size_t cnt)
{
    if (cnt == model_num)
        return objects.end();

    size_t count = 0;
    size_t i = 0;

    for (; i < objects.size(); ++i)
    {
        if (objects[i]->is_visible())
            ++count;
        if (count == cnt + 1)
            break;
    }

    if (count != cnt + 1)
        throw ObjectOutOfRangeException(": model_num");
    else
        return objects.begin() + i;
}

ObjectIter CompositeObject::cam_cnt(const size_t cnt)
{
    if (cnt == cam_num)
        return objects.end();

    size_t count = 0;
    size_t i = 0;

    for (; i < objects.size(); ++i)
    {
        if (!objects[i]->is_visible())
            ++count;
        if (count == cnt + 1)
            break;
    }

    if (count != cnt + 1)
        throw ObjectOutOfRangeException(": cam_cnt");
    else
        return objects.begin() + i;
}


