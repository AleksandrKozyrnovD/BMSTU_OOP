#ifndef SOLUTIONTRANSFORM_H
#define SOLUTIONTRANSFORM_H

#include "basesolution.h"
#include "../modelvisitor/modelvisitor.h"
#include "../builder/directorcreator.h"
#include "../object/abstractobject.h"
#include <memory>

// template <typename Derived, typename Base>
// concept Derivative = std::is_abstract_v<Base> && std::is_base_of_v<Base, Derived>;

// template <typename Type>
// concept NotAbstract = !std::is_abstract_v<Type>;

template<typename Type>
concept ConstructibleDouble = std::is_constructible_v<Type, double, double, double>;

class SolutionTransform : public BaseSolution
{
public:
    SolutionTransform() noexcept;
    explicit SolutionTransform(const std::shared_ptr<ModelVisitor> visitor) noexcept;


    // void set_visitor(const std::shared_ptr<ModelVisitor> visitor) noexcept;

    template<typename visitor>
        requires Derivative<visitor, ModelVisitor> && NotAbstract<visitor> && ConstructibleDouble<visitor>
    void set_visitor(double x, double y, double z) { this->visitor = std::make_shared<visitor>(x, y, z); }

    void transform(std::shared_ptr<AbstractObject>& object) const;

protected:
    std::shared_ptr<ModelVisitor> visitor;
};

#endif // SOLUTIONTRANSFORM_H
