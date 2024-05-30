#include "drawcommand.h"
#include "../draw/drawall.h"
#include "../draw/qtfactory.h"

ChangeDrawSimple::ChangeDrawSimple(std::shared_ptr<QGraphicsScene> scene)
    : scene(scene)
{}

void ChangeDrawSimple::execute()
{
    std::shared_ptr<AbstractGraphicFactory> factory = std::make_shared<QTFactory>(this->scene);
    std::shared_ptr<Camera> camera = this->proxy.scene->get_camera();

    std::shared_ptr<DrawVisitor> visitor = std::make_shared<DrawAll>(factory, camera);

    this->proxy.draw->set_visitor(visitor);
}

ChangeDrawComplex::ChangeDrawComplex(std::shared_ptr<QGraphicsScene> scene)
    : scene(scene)
{}

void ChangeDrawComplex::execute()
{
    std::shared_ptr<AbstractGraphicFactory> factory = std::make_shared<QTFactory>(this->scene);
    std::shared_ptr<Camera> camera = this->proxy.scene->get_camera();

    std::shared_ptr<DrawVisitor> visitor = std::make_shared<DrawAll>(factory, camera);

    this->proxy.draw->set_visitor(visitor);
}

void Draw::execute()
{
    auto objs = this->proxy.scene->get_scene()->get_models();
    std::shared_ptr<Camera> camera = this->proxy.scene->get_camera();

    this->proxy.draw->set_camera(camera);

    for (auto& elem : objs)
    {
        this->proxy.draw->accept(elem);
    }
}
