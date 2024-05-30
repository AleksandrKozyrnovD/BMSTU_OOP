#ifndef MOVEVISITOR_H
#define MOVEVISITOR_H

#include "modelvisitor.h"

class MoveVisitor : public ModelVisitor
{
public:
    MoveVisitor() = default;
    MoveVisitor(double x, double y, double z);
    MoveVisitor(const MoveVisitor& other) = default;
    MoveVisitor(MoveVisitor&& other) = default;
    ~MoveVisitor() = default;


    void visit(Model& obj) override;
    void visit(Camera& obj) override;
    void visit(CompositeObject& obj) override;
};

#endif // MOVEVISITOR_H
