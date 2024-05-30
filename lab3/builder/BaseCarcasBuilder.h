#ifndef BASECARCASBUILDER_H
#define BASECARCASBUILDER_H

#include "../object/carcas/AbstractCarcas.h"
#include "../object/model.h"
#include "../loader/abstractreader.h"

class BaseCarcasBuilder
{
public:

    virtual std::shared_ptr<Model> build() = 0;
    virtual void create_model() = 0;

    virtual bool build_points() = 0;
    virtual bool build_links() = 0;

protected:
    std::shared_ptr<AbstractCarcas> model { nullptr };
    std::shared_ptr<AbstractReader> reader;
};

#endif // BASECARCASBUILDER_H
