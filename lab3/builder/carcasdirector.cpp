#include "carcasdirector.h"
#include "../object/carcas/carcas.h"


CarcasDirector::CarcasDirector() {}

CarcasDirector::CarcasDirector(std::shared_ptr<BaseCarcasBuilder> builder)
{
    this->builder = builder;
    // this->reader = reader;
}

std::shared_ptr<AbstractObject> CarcasDirector::create()
{
    builder->build_points();
    builder->build_links();

    return builder->build();
}
