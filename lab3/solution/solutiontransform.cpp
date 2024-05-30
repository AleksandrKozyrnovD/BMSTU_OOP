#include "solutiontransform.h"

SolutionTransform::SolutionTransform() noexcept {}


SolutionTransform::SolutionTransform(const std::shared_ptr<ModelVisitor> visitor) noexcept
    : visitor(visitor)
{}

// void SolutionTransform::set_visitor(const std::shared_ptr<ModelVisitor> visitor) noexcept
// {
//     this->visitor = visitor;
// }

// template<typename visitor>
//     requires Derivative<visitor, ModelVisitor> && NotAbstract<visitor> && Constructible<visitor>
// void SolutionTransform::set_visitor(double x, double y, double z)
// {
//     this->visitor = std::make_shared<visitor>(x, y, z);
// }

void SolutionTransform::transform(std::shared_ptr<AbstractObject>& object) const
{
    object->accept(this->visitor);
}
