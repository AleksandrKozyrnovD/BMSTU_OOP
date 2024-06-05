#include "qtdrawer.h"
#include "../object/carcas/carcas.h"
#include <iostream>


QTDrawer::QTDrawer(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* view)
    : scene(scene), view(view)
{}

void QTDrawer::draw_line(const Point& A, const Point& B)
{
    auto cont = this->view->contentsRect();

    // std::cout << cont.width() << std::endl;
    // std::cout << cont.height() << std::endl;
    this->scene->addLine(A.get_x() + 0 / 2, A.get_y() + 0 / 2,
                         B.get_x() + 0 / 2, B.get_y() + 0 / 2);
}

void QTDrawer::clear_scene()
{
    this->scene->clear();
}
