#ifndef EDGE_H
#define EDGE_H

#include <stdio.h>

class Edge
{
public:
    Edge();
    Edge(const size_t source, const size_t goal);
    Edge(const Edge& edge);
    Edge(Edge&& edge);
    ~Edge();

    Edge& operator =(const Edge& edge);
    Edge& operator =(Edge&& edge);

    size_t get_source() const;
    size_t get_goal() const;

    void set_source(const size_t source);
    void set_goal(const size_t goal);
private:
    size_t source;
    size_t goal;
};

#endif // EDGE_H
