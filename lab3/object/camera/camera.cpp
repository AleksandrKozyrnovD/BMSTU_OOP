#include "camera.h"

Camera::Camera(double x, double y, double z)
    : center(x, y, z)
{
    this->up = Point(0, 1, 0);
    this->forward = Point(0, 0, 1);
    this->right = Point(1, 0, 0);
}

void Camera::accept(std::shared_ptr<AbstractVisitor> visitor)
{
    visitor->visit(*this);
}
