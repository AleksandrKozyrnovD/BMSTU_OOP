#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "abstractgraphicfactory.h"
#include <QGraphicsScene>
#include <QGraphicsView>

class QTFactory : public AbstractGraphicFactory
{
public:
    QTFactory();
    explicit QTFactory(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* view);
    ~QTFactory() = default;

    std::shared_ptr<AbstractDrawer> get_drawer() override;

protected:
    std::shared_ptr<QGraphicsScene> scene;
    QGraphicsView* view;
};

#endif // QTFACTORY_H
