#include "loader.h"


Loader::Loader() {}


std::shared_ptr<AbstractObject> Loader::load(std::shared_ptr<BaseDirector> director)
{
    return director->create();
}
