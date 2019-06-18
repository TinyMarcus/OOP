#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "object.h"
#include "node.h"
#include "edge.h"

class Model : public VisibleObject
{
public:
    Model() = default;
    Model(const std::vector<Node> nodes, const std::vector<Edge> edges);
    Model(const Model& model);
    Model(Model&& model);
    ~Model() = default;

    Model& operator =(const Model& model);
    Model& operator =(Model&& model);

    const std::vector<Node> get_nodes() const;
    const std::vector<Edge> get_edges() const;

    void add_node(const Node& node);
    void add_edge(const Edge& edge);

    void move(const double x, const double y, const double z);
    void scale(const double x, const double y, const double z);
    void rotate(const double x, const double y, const double z);
private:
    std::vector<Node> nodes;
    std::vector<Edge> edges;
};

#endif // MODEL_H
