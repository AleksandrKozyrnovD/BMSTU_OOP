#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <memory>
#include <vector>
// #include "../modelvisitor/modelvisitor.h"
// #include "../draw/drawvisitor.h"

#include "../visitor/abstractvisitor.h"

class AbstractObject;
using Iterator = std::vector<std::shared_ptr<AbstractObject>>::iterator;

class AbstractObject
{
public:
    AbstractObject() { this->id = nextid++; };
    virtual ~AbstractObject() = default;

    virtual bool IsDrawable()  { return false; }
    virtual bool IsComposite() { return false; }

    virtual bool add(const std::shared_ptr<AbstractObject>& obj) { return false; }
    virtual bool remove(const Iterator& iterator) { return false; }

    virtual Iterator begin() { return Iterator(); }
    virtual Iterator end()   {return Iterator(); }

    virtual void accept(std::shared_ptr<AbstractVisitor> visitor) = 0;
    // virtual void accept(std::shared_ptr<ModelVisitor> visitor) = 0;
    // virtual void accept(std::shared_ptr<DrawVisitor> visitor) = 0;

    size_t get_id() { return this->id; }

protected:
    std::size_t id;
    static std::size_t nextid;
};


class Drawable : public AbstractObject
{
public:
    Drawable() = default;
    ~Drawable() override = default;

    bool IsDrawable() override { return true; }
};

class Undrawable : public AbstractObject
{
public:
    Undrawable() = default;
    ~Undrawable() override = default;

    bool IsDrawable() override { return false; }
};


class CompositeObject : public AbstractObject
{
public:
    using iterator = Iterator;
    using value_type = AbstractObject;
    using iterator_rag = std::random_access_iterator_tag;
    using pointer = std::shared_ptr<AbstractObject>;
    using reference = AbstractObject&;

    CompositeObject() = default;
    explicit CompositeObject(std::shared_ptr<AbstractObject>& object);
    explicit CompositeObject(std::vector<std::shared_ptr<AbstractObject>>& vector);

    bool IsDrawable() override;
    bool IsComposite() override;

    bool add(const std::shared_ptr<AbstractObject>& obj) override;
    bool remove(const Iterator& iterator) override;

    void accept(std::shared_ptr<AbstractVisitor> visitor) override;
    // void accept(std::shared_ptr<ModelVisitor> visitor) override;
    // void accept(std::shared_ptr<DrawVisitor> visitor) override;

    std::vector<std::shared_ptr<AbstractObject>>& get();

    Iterator begin() override;
    Iterator end() override;

private:
    std::vector<std::shared_ptr<AbstractObject>> elements;
};

#endif // ABSTRACTOBJECT_H
