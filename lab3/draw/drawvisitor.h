#ifndef DRAWVISITOR_H
#define DRAWVISITOR_H

#include "abstractgraphicfactory.h"
#include <memory>
// #include "../object/model.h"
// #include "../object/camera/camera.h"


// class AbstractCarcas;
// class Camera;
// class CompositeObject;

#include "../visitor/abstractvisitor.h"

class DrawVisitor : public AbstractVisitor
{
public:
    DrawVisitor();
    DrawVisitor(const DrawVisitor& visitor) = default;
    ~DrawVisitor() = default;

    // virtual void visit(AbstractCarcas& obj) = 0;
    // virtual void visit(Camera& obj) = 0;
    // virtual void visit(CompositeObject& obj) = 0;

    void set_camera(std::shared_ptr<Camera> camera) { this->camera = camera; }

protected:
    std::shared_ptr<AbstractGraphicFactory> factory;
    std::shared_ptr<Camera> camera;

    Point get_proection(const Point& point);

    void get_line_proection(Point& A, Point& B);
};

#endif // DRAWVISITOR_H
