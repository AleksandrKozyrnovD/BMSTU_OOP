#ifndef CAMERA_H
#define CAMERA_H

#include "../abstractobject.h"

class Camera : public Undrawable
{
public:
    Camera() = default;
    Camera(double x, double y, double z);
    Camera(double x, double y, double z,
           double ox, double oy, double oz);
    ~Camera() = default;


    void accept(std::shared_ptr<AbstractVisitor> visitor) override;
    // void accept(std::shared_ptr<ModelVisitor> visitor) override;
    // void accept(std::shared_ptr<DrawVisitor> visitor) override;

public:
    double x, y, z;
    double ox, oy, oz;
    double distance;
};

#endif // CAMERA_H
