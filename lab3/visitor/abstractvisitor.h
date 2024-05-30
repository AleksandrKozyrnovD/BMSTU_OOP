#ifndef ABSTRACTVISITOR_H
#define ABSTRACTVISITOR_H


class CompositeObject;
class Model;
class Camera;


class AbstractVisitor
{
public:
    AbstractVisitor();
    virtual ~AbstractVisitor() = default;

    virtual void visit(Model& obj) = 0;
    virtual void visit(Camera& obj) = 0;
    virtual void visit(CompositeObject& obj) = 0;
};

#endif // ABSTRACTVISITOR_H
