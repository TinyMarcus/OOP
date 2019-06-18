#include "node.h"

Node::Node() : x(0), y(0), z(0) {}

Node::Node(const double x, const double y, const double z) : x(x), y(y), z(z) {}

Node::Node(const Node& node)
{
    this->x = node.x;
    this->y = node.y;
    this->z = node.z;
}

Node::Node(Node &&node)
{
    this->x = node.x;
    this->y = node.y;
    this->z = node.z;
    node.~Node();
}

Node::~Node()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Node& Node::operator =(const Node& node)
{
    this->x = node.x;
    this->y = node.y;
    this->z = node.z;

    return *this;
}

Node& Node::operator =(Node&& node)
{
    this->x = node.x;
    this->y = node.y;
    this->z = node.z;
    node.~Node();

    return *this;
}

double Node::get_x() const
{
    return x;
}

double Node::get_y() const
{
    return y;
}

double Node::get_z() const
{
    return z;
}

void Node::set_x(const double x)
{
    this->x = x;
}

void Node::set_y(const double y)
{
    this->y = y;
}

void Node::set_z(const double z)
{
    this->z = z;
}

void Node::move(const double dx, const double dy, const double dz)
{
    this->x += dx;
    this->y += dy;
    this->z += dz;
}

void Node::scale(const double kx, const double ky, const double kz)
{
    this->x = this->x * kx;
    this->y = this->y * ky;
    this->z = this->z * kz;
}

void Node::rotate_x(const double angle)
{
    const double tmp = this->y;
    this->y = this->y * cos(angle) + this->z * sin(angle);
    this->z = -tmp * sin(angle) + this->z * cos(angle);
}

void Node::rotate_y(const double angle)
{
    const double tmp = this->z;
    this->z = this->z * cos(angle) + this->x * sin(angle);
    this->x = -tmp * sin(angle) + this->x * cos(angle);
}

void Node::rotate_z(const double angle)
{
    const double tmp = this->x;
    this->x = this->x * cos(angle) + this->y * sin(angle);
    this->y = -tmp * sin(angle) + this->y * cos(angle);
}

