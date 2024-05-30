#include "drawvisitor.h"
#include "../object/camera/camera.h"
#include "../object/carcas/carcas.h"

DrawVisitor::DrawVisitor() {}


Point DrawVisitor::get_proection(const Point& point)
{
    auto copy = point;
    // copy.rotate(camera->ox, camera->oy, camera->oz);
    // copy.move(0, 0, camera->z);

    // copy.rotate(camera->ox, 0, 0);
    // double x = camera->x + copy.get_x();
    // copy.rotate(0, camera->oy, 0);
    // double y = camera->y + copy.get_y();
    // copy.rotate(0, 0, camera->oz);
    // double z = camera->z + copy.get_z();



    Point center(camera->x, camera->y, camera->z);
    // copy.move(camera->x, camera->y, camera->z);
    // copy.set_x(-copy.get_x() + copy.get_x() * (camera->distance / copy.get_z()));
    // copy.set_y(-copy.get_y() + copy.get_y() * (camera->distance / copy.get_z()));
    copy.rotate(center, -camera->ox, -camera->oy, -camera->oz);

    copy.move(camera->x, camera->y, camera->z);

    return copy;
}
