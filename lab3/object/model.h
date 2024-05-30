#ifndef MODEL_H
#define MODEL_H

#include "abstractobject.h"
#include "carcas/AbstractCarcas.h"
// #include "../modelvisitor/modelvisitor.h"
// #include "../draw/drawvisitor.h"

using Modelptr = std::shared_ptr<AbstractCarcas>;

class Model : public Drawable
{
    friend class MoveVisitor;
    friend class RotateVisitor;
    friend class ScaleVisitor;
    friend class DrawAll;
    friend class DrawComplex;
public:
    Model() = default;
    Model(const Model& other) = default;
    explicit Model(const Modelptr& model) noexcept;

    void accept(std::shared_ptr<AbstractVisitor> visitor) override;


protected:
    Modelptr model;
};

#endif // MODEL_H
