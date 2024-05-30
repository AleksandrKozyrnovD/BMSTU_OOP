#include "movevisitor.h"
#include "../object/carcas/carcas.h"
#include "../object/camera/camera.h"
#include "../object/abstractobject.h"
#include "../object/model.h"

MoveVisitor::MoveVisitor(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void MoveVisitor::visit(Model& obj) //visit model
{
    std::vector<Point>& points = obj.model->get_points();
    for (auto& elem : points)
    {
        elem.move(this->x, this->y, this->z);
    }

    obj.model->get_center().move(this->x, this->y, this->z);

    return;
}

void MoveVisitor::visit(Camera& obj)
{
    obj.x += this->x;
    obj.y += this->y;
    obj.z += this->z;
}

void MoveVisitor::visit(CompositeObject& obj)
{
    obj.accept(std::make_shared<MoveVisitor>(*this));
}
