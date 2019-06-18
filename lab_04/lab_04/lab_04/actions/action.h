#ifndef ACTION_H
#define ACTION_H

#include "facade/facade.h"
#include "workers/modelbuilder.h"
#include "workers/modelio.h"
#include "workers/objecttransformator.h"
#include "transformations/transformations.h"

class BaseAction
{
public:
    BaseAction() = default;
    virtual ~BaseAction() = default;

    virtual void make(std::shared_ptr<Facade> facade) = 0;
};

class ModelIOAction : public BaseAction
{
public:
    explicit ModelIOAction(const std::string& file) : file(file) {}
    ~ModelIOAction() = default;

    void make(std::shared_ptr<Facade> facade) override
    {
        ModelIO io(file);
        ModelBuilder builder;
        facade->add_model(io, builder);
    }
private:
    std::string file;
};

class ModelMoveAction : public BaseAction
{
public:
    explicit ModelMoveAction(const double dx, const double dy, const double dz, \
                             const size_t cnt) : dx(dx), dy(dy), dz(dz), model_cnt(cnt) {}
    ~ModelMoveAction() = default;

    void make(std::shared_ptr<Facade> facade) override
    {
        Moving move(dx, dy, dz);
        ModelTransformator transform(move);
        facade->transform_model(transform, model_cnt);
    }
private:
    double dx, dy, dz;
    size_t model_cnt;
};

class ModelScaleAction : public BaseAction
{
public:
    explicit ModelScaleAction(const double kx, const double ky, const double kz, \
                             const size_t cnt) : kx(kx), ky(ky), kz(kz), model_cnt(cnt) {}
    ~ModelScaleAction() = default;

    void make(std::shared_ptr<Facade> facade) override
    {
        Scaling scale(kx, ky, kz);
        ModelTransformator transform(scale);
        facade->transform_model(transform, model_cnt);
    }
private:
    double kx, ky, kz;
    size_t model_cnt;
};

class ModelRotateAction : public BaseAction
{
public:
    explicit ModelRotateAction(const double x, const double y, const double z, \
                             const size_t cnt) : x(x), y(y), z(z), model_cnt(cnt) {}
    ~ModelRotateAction() = default;

    void make(std::shared_ptr<Facade> facade) override
    {
        Rotating rotate(x, y, z);
        ModelTransformator transform(rotate);
        facade->transform_model(transform, model_cnt);
    }
private:
    double x, y, z;
    size_t model_cnt;
};

class CameraAddAction : public BaseAction
{
public:
    explicit CameraAddAction(const double x_angle, const double y_angle, const double z_angle) \
        : x_angle(x_angle), y_angle(y_angle), z_angle(z_angle) {}
    ~CameraAddAction() = default;

    void make(std::shared_ptr<Facade> facade) override
    {
        facade->add_cam();
    }
private:
    double x_angle, y_angle, z_angle;
};

class CameraDelAction : public BaseAction
{
public:
    explicit CameraDelAction(size_t cnt) : cnt(cnt) {}
    ~CameraDelAction() = default;

    void make(std::shared_ptr<Facade> facade) override
    {
        facade->del_cam(this->cnt);
    }
private:
    size_t cnt;
};

class CameraRotateAction : public BaseAction
{
public:
    explicit CameraRotateAction(const double x, const double y, const double z, const size_t cnt)
        : x_angle(x), y_angle(y), z_angle(z), camera_cnt(cnt) {}
    ~CameraRotateAction() = default;

    void make(std::shared_ptr<Facade> facade) override
    {
        Rotating rotate(x_angle, y_angle, z_angle);
        CameraTransformator transform(rotate);
        facade->transform_cam(transform, camera_cnt);
    }
private:
    double x_angle, y_angle, z_angle;
    size_t camera_cnt;
};

class ModelDrawAction : public BaseAction
{
public:
    explicit ModelDrawAction(ModelDrawer draw, const size_t cnt) : drawer(draw), camera_cnt(cnt) {}
    ~ModelDrawAction() = default;

    void make(std::shared_ptr<Facade> facade) override
    {
        facade->draw(drawer, camera_cnt);
    }
private:
    ModelDrawer drawer;
    size_t camera_cnt;
};

#endif // ACTION_H
