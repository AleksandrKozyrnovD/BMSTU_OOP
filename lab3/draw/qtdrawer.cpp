#include "qtdrawer.h"
#include "../object/carcas/carcas.h"

QTDrawer::QTDrawer(std::shared_ptr<QGraphicsScene> scene)
    : scene(scene)
{}

void QTDrawer::draw_line(const Point& A, const Point& B)
{
    this->scene->addLine(A.get_x(), A.get_y(), B.get_x(), B.get_y());
}

void QTDrawer::clear_scene()
{
    this->scene->clear();
}
