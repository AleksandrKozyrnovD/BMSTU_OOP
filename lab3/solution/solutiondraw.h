#ifndef SOLUTIONDRAW_H
#define SOLUTIONDRAW_H

#include "basesolution.h"
#include "../draw/drawvisitor.h"
#include "../object/abstractobject.h"
#include "../object/camera/camera.h"

class SolutionDraw : public BaseSolution
{
public:
    SolutionDraw();
    explicit SolutionDraw(std::shared_ptr<DrawVisitor> visitor);
    ~SolutionDraw() = default;

    // void visit(std::shared_ptr<CompositeObject> composite);

    void set_visitor(std::shared_ptr<DrawVisitor> visitor);
    void accept(std::shared_ptr<AbstractObject> obj);
    void set_camera(std::shared_ptr<Camera> camera);

protected:
    std::shared_ptr<DrawVisitor> visitor;
};

#endif // SOLUTIONDRAW_H
