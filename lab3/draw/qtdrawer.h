#ifndef QTDRAWER_H
#define QTDRAWER_H

#include "abstractdrawer.h"
#include <QGraphicsScene>
#include <QGraphicsView>

class QTDrawer : public AbstractDrawer
{
public:
    QTDrawer() = delete;
    ~QTDrawer() = default;

    explicit QTDrawer(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* view);

    void draw_line(const Point& A, const Point& B) override;
    void clear_scene() override;

protected:
    std::shared_ptr<QGraphicsScene> scene;
    QGraphicsView* view;
};

#endif // QTDRAWER_H
