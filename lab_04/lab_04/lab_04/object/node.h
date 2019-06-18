#ifndef NODE_H
#define NODE_H

#include <cmath>

class Node
{
public:
    Node();
    Node(const double x, const double y, const double z);
    Node(const Node& node);
    Node(Node&& node);
    ~Node();

    Node& operator =(const Node& node);
    Node& operator =(Node&& node);

    double get_x() const;
    double get_y() const;
    double get_z() const;

    void set_x(const double x);
    void set_y(const double y);
    void set_z(const double z);

    void move(const double dx, const double dy, const double dz);
    void scale(const double kx, const double ky, const double kz);
    void rotate_x(const double angle);
    void rotate_y(const double angle);
    void rotate_z(const double angle);
private:
    double x;
    double y;
    double z;
};


#endif // NODE_H
