#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "abstractgraphicfactory.h"
#include <QGraphicsScene>

class QTFactory : public AbstractGraphicFactory
{
public:
    QTFactory();
    explicit QTFactory(std::shared_ptr<QGraphicsScene> scene);
    ~QTFactory() = default;

    std::shared_ptr<AbstractDrawer> get_drawer() override;

protected:
    std::shared_ptr<QGraphicsScene> scene;
};

#endif // QTFACTORY_H
