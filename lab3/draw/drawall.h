#ifndef DRAWALL_H
#define DRAWALL_H

#include "drawvisitor.h"

class DrawAll : public DrawVisitor
{
public:
    DrawAll();
    DrawAll(std::shared_ptr<AbstractGraphicFactory> factory, std::shared_ptr<Camera>  camera);
    DrawAll(const DrawAll& visitor);
    ~DrawAll() = default;

    void visit(Model& carcas) override;
    void visit(Camera& camera) override;
    void visit(CompositeObject& composite) override;
};

#endif // DRAWALL_H
