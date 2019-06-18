#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsScene>

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void draw_line(const double x_beg, const double y_beg, const double x_end, const double y_end) = 0;
};

class ModelDrawer : public BaseDrawer
{
public:
    ModelDrawer(QGraphicsScene* canvas) : BaseDrawer(), canvas(canvas) {}
    ~ModelDrawer() = default;

    void draw_line(const double x_beg, const double y_beg, const double x_end, const double y_end) override
    {
        canvas->addLine(x_beg, y_beg, x_end, y_end);
    }

private:
    QGraphicsScene* canvas;
};


#endif // DRAWER_H
