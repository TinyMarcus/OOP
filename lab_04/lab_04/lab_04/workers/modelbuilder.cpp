#include "modelbuilder.h"

ModelBuilder::ModelBuilder() : model(nullptr) {}

std::shared_ptr<Model> ModelBuilder::get_model() const
{
    return model;
}

void ModelBuilder::build_model()
{
    model = std::make_shared<Model>();
}

void ModelBuilder::build_node(const double x, const double y, const double z)
{
    if (!is_model_built())
    {
        throw BuilderException();
    }

    Node node(x, y, z);
    this->model->add_node(node);
}

void ModelBuilder::build_edge(const size_t source, const size_t goal)
{
    if (!is_model_built())
    {
        throw BuilderException();
    }

    Edge edge(source, goal);
    this->model->add_edge(edge);
}

bool ModelBuilder::is_model_built() const
{
    return (this->model != nullptr) ? true : false;
}
