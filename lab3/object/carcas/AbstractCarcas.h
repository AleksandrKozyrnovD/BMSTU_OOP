#ifndef ABSTRACTCARCAS_H
#define ABSTRACTCARCAS_H

#include <vector>
#include <memory>
#include "../../modelvisitor/modelvisitor.h"
#include "../../draw/drawvisitor.h"

class Point;
class Link;

using PointVector = std::vector<Point>;
using LinkVector = std::vector<Link>;

class AbstractCarcas
{
public:
    AbstractCarcas() = default;
    virtual ~AbstractCarcas() = default;

    virtual PointVector& get_points() = 0;
    virtual LinkVector get_links() = 0;

    virtual bool add_point(const Point& point) = 0;
    virtual bool add_link(const Link& link) = 0;

    virtual Point& get_center() = 0;

    virtual void move_to_center() = 0;
    virtual void move_back() = 0;
};

#endif // ABSTRACTCARCAS_H
