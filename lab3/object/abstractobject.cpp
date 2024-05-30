#include "abstractobject.h"

std::size_t AbstractObject::nextid = 0;

CompositeObject::CompositeObject(std::shared_ptr<AbstractObject> &element)
{
    this->elements.push_back(element);
}

CompositeObject::CompositeObject(std::vector<std::shared_ptr<AbstractObject>>& vector)
{
    this->elements = vector;
}

bool CompositeObject::add(const std::shared_ptr<AbstractObject> &element)
{
    this->elements.push_back(element);

    return true;
}

bool CompositeObject::remove(const Iterator &iter)
{
    this->elements.erase(iter);

    return true;
}

bool CompositeObject::IsDrawable()
{
    return false;
}

bool CompositeObject::IsComposite()
{
    return true;
}

Iterator CompositeObject::begin()
{
    return this->elements.begin();
}

Iterator CompositeObject::end()
{
    return this->elements.end();
}

// void CompositeObject::accept(std::shared_ptr<ModelVisitor> visitor)
// {
//     for (const auto &element : this->elements)
//     {
//         element->accept(visitor);
//     }
// }

// void CompositeObject::accept(std::shared_ptr<DrawVisitor> visitor)
// {
//     for (auto &element : this->elements)
//     {
//         element->accept(visitor);
//     }
// }

void CompositeObject::accept(std::shared_ptr<AbstractVisitor> visitor)
{
    for (auto &element : this->elements)
    {
        element->accept(visitor);
    }
}

std::vector<std::shared_ptr<AbstractObject>>& CompositeObject::get()
{
    return this->elements;
}
