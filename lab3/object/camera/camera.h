#ifndef CAMERA_H
#define CAMERA_H

#include "../abstractobject.h"
#include "../carcas/carcas.h"

class Camera : public Undrawable
{
public:
    Camera() = default;
    Camera(double x, double y, double z);
    ~Camera() = default;


    void accept(std::shared_ptr<AbstractVisitor> visitor) override;

public:
    Point center;

    Point up;
    Point forward;
    Point right;
};

#endif // CAMERA_H
