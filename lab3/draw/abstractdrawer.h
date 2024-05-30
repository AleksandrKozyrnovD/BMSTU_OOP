#ifndef ABSTRACTDRAWER_H
#define ABSTRACTDRAWER_H

// #include "../object/carcas/carcas.h"
class Point;

class AbstractDrawer
{
public:
    AbstractDrawer();
    virtual ~AbstractDrawer() = default;

    virtual void draw_line(const Point& p1, const Point& p2) = 0;
    virtual void clear_scene() = 0;
};

#endif // ABSTRACTDRAWER_H
