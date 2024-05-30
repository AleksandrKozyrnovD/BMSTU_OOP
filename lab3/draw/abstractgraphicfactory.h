#ifndef ABSTRACTGRAPHICFACTORY_H
#define ABSTRACTGRAPHICFACTORY_H

#include "abstractdrawer.h"
#include <memory>

class AbstractGraphicFactory
{
public:
    AbstractGraphicFactory();
    virtual ~AbstractGraphicFactory() = default;

    virtual std::shared_ptr<AbstractDrawer> get_drawer() = 0;
};

#endif // ABSTRACTGRAPHICFACTORY_H
