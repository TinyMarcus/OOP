#ifndef OBJECTTRANSFORMATOR_H
#define OBJECTTRANSFORMATOR_H

#include "transformations/transformations.h"
#include "object/compositeobject.h"

class BaseTransformator
{
public:
    BaseTransformator() = default;
    virtual ~BaseTransformator() = default;

    virtual void transform(std::shared_ptr<Object> obj) = 0;
};

class ModelTransformator : public BaseTransformator
{
public:
    ModelTransformator(BaseTransformations& trans);
    ~ModelTransformator() = default;

    void transform(std::shared_ptr<Object> obj);
private:
    BaseTransformations& trans;
};

class CameraTransformator : public BaseTransformator
{
public:
    CameraTransformator(BaseTransformations& trans);
    ~CameraTransformator() = default;

    void transform(std::shared_ptr<Object> obj);
private:
    BaseTransformations& trans;
};

#endif // OBJECTTRANSFORMATOR_H
