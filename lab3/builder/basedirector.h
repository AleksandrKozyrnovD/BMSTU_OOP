#ifndef BASEDIRECTOR_H
#define BASEDIRECTOR_H

#include "../loader/abstractreader.h"
#include "BaseCarcasBuilder.h"
#include "../object/abstractobject.h"


class BaseDirector
{
public:
    BaseDirector();
    virtual ~BaseDirector() = default;
    // BaseDirector(std::shared_ptr<BaseCarcasBuilder>& builder, std::shared_ptr<AbstractReader>& reader);

    virtual std::shared_ptr<AbstractObject> create() = 0;

protected:
    std::shared_ptr<BaseCarcasBuilder> builder;
};

#endif // BASEDIRECTOR_H
