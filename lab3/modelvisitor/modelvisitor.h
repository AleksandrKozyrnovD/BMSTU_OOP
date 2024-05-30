#ifndef MODELVISITOR_H
#define MODELVISITOR_H

// class CompositeObject;
// class AbstractCarcas;
// class Camera;
#include "../visitor/abstractvisitor.h"


class ModelVisitor : public AbstractVisitor
{
// public:
    // ModelVisitor() = default;
//     ModelVisitor(const ModelVisitor& other) = default;
//     ModelVisitor(ModelVisitor&& other) = default;
//     ~ModelVisitor() = default;

//     virtual void visit(AbstractCarcas& obj) = 0;
//     virtual void visit(Camera& obj) = 0;
//     virtual void visit(CompositeObject& obj) = 0;

protected:
    double x, y, z;
};

#endif // MODELVISITOR_H
