#ifndef QTDRAWER_H
#define QTDRAWER_H

#include "abstractdrawer.h"
#include <QGraphicsScene>

class QTDrawer : public AbstractDrawer
{
public:
    QTDrawer() = delete;
    ~QTDrawer() = default;

    explicit QTDrawer(std::shared_ptr<QGraphicsScene> scene);

    void draw_line(const Point& A, const Point& B) override;
    void clear_scene() override;

protected:
    std::shared_ptr<QGraphicsScene> scene;
};

#endif // QTDRAWER_H
