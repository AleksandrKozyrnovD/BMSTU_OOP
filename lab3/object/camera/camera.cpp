#include "camera.h"

Camera::Camera(double x, double y, double z)
    : x(x), y(y), z(z)
{
    distance = 1;
    ox = oy = oz = 0.0;
}

Camera::Camera(double x, double y, double z,
       double ox, double oy, double oz)
    : x(x), y(y), z(z), ox(ox), oy(oy), oz(oz)
{
    distance = 1;
}

void Camera::accept(std::shared_ptr<AbstractVisitor> visitor)
{
    visitor->visit(*this);
}
