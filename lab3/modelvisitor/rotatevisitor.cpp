#include "rotatevisitor.h"
#include "../object/carcas/carcas.h"
#include "../object/camera/camera.h"
#include "../object/model.h"

RotateVisitor::RotateVisitor(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void RotateVisitor::visit(Model& obj)
{
    obj.model->move_to_center();
    std::vector<Point>& points = obj.model->get_points();

    for (auto& elem : points)
    {
        elem.rotate(this->x, this->y, this->z);
    }
    obj.model->move_back();

    return;
}

// #include <cmath>

void RotateVisitor::visit(Camera& obj)
{
    obj.up.rotate(this->x, this->y, this->z);
    obj.forward.rotate(this->x, this->y, this->z);
    obj.right.rotate(this->x, this->y, this->z);
}

void RotateVisitor::visit(CompositeObject& obj)
{
    obj.accept(std::make_shared<RotateVisitor>(*this));
}
