#include "qtfactory.h"
#include "qtdrawer.h"

QTFactory::QTFactory() {}

QTFactory::QTFactory(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* view)
    : scene(scene), view(view)
{}

std::shared_ptr<AbstractDrawer> QTFactory::get_drawer()
{
    return std::make_shared<QTDrawer>(this->scene, this->view);
}
