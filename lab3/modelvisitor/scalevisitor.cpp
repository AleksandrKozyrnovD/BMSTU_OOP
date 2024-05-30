#include "scalevisitor.h"
#include "../object/carcas/carcas.h"
#include "../object/camera/camera.h"
#include "../object/model.h"

ScaleVisitor::ScaleVisitor(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void ScaleVisitor::visit(Model& obj)
{
    obj.model->move_to_center();
    std::vector<Point>& points = obj.model->get_points();
    for (auto& elem : points)
    {
        elem.scale(this->x, this->y, this->z);
    }
    obj.model->move_back();

    return;
}

void ScaleVisitor::visit(Camera& obj)
{
    return;
}

void ScaleVisitor::visit(CompositeObject& obj)
{
    return obj.accept(std::make_shared<ScaleVisitor>(*this));
}
