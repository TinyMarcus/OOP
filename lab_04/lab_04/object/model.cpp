#include "model.h"

Model::Model(const std::vector<Node> nodes, const std::vector<Edge> edges) : \
    nodes(nodes), edges(edges) {}

Model::Model(const Model& model)
{
    this->nodes = model.nodes;
    this->edges = model.edges;
}

Model::Model(Model&& model)
{
    this->nodes = model.nodes;
    this->edges = model.edges;
    model.~Model();
}

Model& Model::operator=(const Model& model)
{
    this->nodes = model.nodes;
    this->edges = model.edges;

    return *this;
}

Model& Model::operator=(Model&& model)
{
    this->nodes = model.nodes;
    this->edges = model.edges;
    model.~Model();

    return *this;
}

const std::vector<Node> Model::get_nodes() const
{
    return this->nodes;
}

const std::vector<Edge> Model::get_edges() const
{
    return this->edges;
}

void Model::add_node(const Node& node)
{
    this->nodes.push_back(node);
}

void Model::add_edge(const Edge& edge)
{
    this->edges.push_back(edge);
}

void Model::move(const double x, const double y, const double z)
{
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        nodes[i].move(x, y, z);
    }
}

void Model::scale(const double x, const double y, const double z)
{
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        nodes[i].scale(x, y, z);
    }
}

void Model::rotate(const double x, const double y, const double z)
{
    for (size_t i = 0; i < nodes.size(); ++i)
    {
        nodes[i].rotate_x(x);
        nodes[i].rotate_y(y);
        nodes[i].rotate_z(z);
    }
}
