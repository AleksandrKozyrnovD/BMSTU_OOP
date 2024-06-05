#ifndef MODELVISITOR_H
#define MODELVISITOR_H

// class CompositeObject;
// class AbstractCarcas;
// class Camera;
#include "../visitor/abstractvisitor.h"


class ModelVisitor : public AbstractVisitor
{
protected:
    double x, y, z;
};

#endif // MODELVISITOR_H
