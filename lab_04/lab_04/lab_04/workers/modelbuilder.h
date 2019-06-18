#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include "object/model.h"
#include "exceptions/builderexception.h"

#include <iostream>
#include <memory>

class BaseBuilder
{
public:
    BaseBuilder() = default;
    virtual ~BaseBuilder() = default;

    virtual std::shared_ptr<Model> get_model() const = 0;
    virtual void build_model() = 0;
    virtual void build_node(const double x, const double y, const double z) = 0;
    virtual void build_edge(const size_t source, const size_t goal) = 0;
};

class ModelBuilder : public BaseBuilder
{
public:
    ModelBuilder();
    ~ModelBuilder() = default;

    std::shared_ptr<Model> get_model() const;
    void build_model();
    void build_node(const double x, const double y, const double z);
    void build_edge(const size_t source, const size_t goal);

protected:
    bool is_model_built() const;
    std::shared_ptr<Model> model;
};

#endif // MODELBUILDER_H
