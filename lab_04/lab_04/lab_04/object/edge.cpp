#include "edge.h"

Edge::Edge() : source(0), goal(0) {}

Edge::Edge(const size_t source, const size_t goal) : source(source), goal(goal) {}

Edge::Edge(const Edge& edge)
{
    this->source = edge.source;
    this->goal = edge.goal;
}

Edge::Edge(Edge &&edge)
{
    this->source = edge.source;
    this->goal = edge.goal;
    edge.~Edge();
}

Edge::~Edge()
{
    this->source = 0;
    this->goal = 0;
}

size_t Edge::get_source() const
{
    return source;
}

size_t Edge::get_goal() const
{
    return goal;
}

void Edge::set_source(const size_t source)
{
    this->source = source;
}

void Edge::set_goal(const size_t goal)
{
    this->goal = goal;
}

Edge& Edge::operator=(const Edge &edge)
{
    this->source = edge.source;
    this->goal = edge.goal;

    return *this;
}

Edge& Edge::operator=(Edge &&edge)
{
    this->source = edge.source;
    this->goal = edge.goal;
    edge.~Edge();

    return *this;
}
