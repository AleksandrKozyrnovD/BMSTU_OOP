#include "qtfactory.h"
#include "qtdrawer.h"

QTFactory::QTFactory() {}

QTFactory::QTFactory(std::shared_ptr<QGraphicsScene> scene)
    : scene(scene)
{}

std::shared_ptr<AbstractDrawer> QTFactory::get_drawer()
{
    return std::make_shared<QTDrawer>(this->scene);
}
