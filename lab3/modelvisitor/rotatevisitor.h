#ifndef ROTATEVISITOR_H
#define ROTATEVISITOR_H

#include "modelvisitor.h"

class RotateVisitor : public ModelVisitor
{
public:
    RotateVisitor() = default;
    RotateVisitor(double x, double y, double z);
    RotateVisitor(const RotateVisitor& other) = default;
    RotateVisitor(RotateVisitor&& other) = default;
    ~RotateVisitor() = default;


    void visit(Model& obj) override;
    void visit(Camera& obj) override;
    void visit(CompositeObject& obj) override;
};

#endif // ROTATEVISITOR_H
