#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
    Object() = default;
    virtual ~Object() = default;

    virtual bool is_visible() = 0;
};

class VisibleObject : public Object
{
public:
    VisibleObject() = default;
    virtual ~VisibleObject() = default;

    bool is_visible() override { return true; }
};


class InvisibleObject : public Object
{
public:
    InvisibleObject() = default;
    virtual ~InvisibleObject() = default;

    bool is_visible() override { return false; }
};

#endif // OBJECT_H
