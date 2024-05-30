#ifndef SOLUTIONLOADER_H
#define SOLUTIONLOADER_H

#include "basesolution.h"
#include "../object/abstractobject.h"
#include "../loader/loader.h"
#include "../builder/carcasdirector.h"
#include "../loader/filereader.h"
#include "../builder/carcasbuilder.h"


class SolutionLoader : public BaseSolution
{
public:
    SolutionLoader();
    // explicit SolutionLoader(const std::shared_ptr<Loader>& loader) noexcept;
    ~SolutionLoader() = default;

    //Извините за мусорку в .h, в .cpp нельзя указывать шаблоны!!! .hpp не вариант
    // template<Derivative<BaseDirector> director, typename ...Args>
    // requires NotAbstract<director> && Constructible<director, Args...>
    // static std::shared_ptr<AbstractObject> load(Args ...args)
    // {
    //     std::shared_ptr<BaseDirector> myDirector = DirectorCreator::create<director>(args...);

    //     return Loader::load(myDirector);
    // }

    std::shared_ptr<AbstractObject> load_from_simple_file(const std::string& filename)
    {

        std::shared_ptr<AbstractReader> reader = std::make_shared<FileReader>(filename);
        std::shared_ptr<BaseCarcasBuilder> builder = std::make_shared<CarcasBuilder>(reader);

        std::shared_ptr<BaseDirector> myDirector = DirectorCreator::create<CarcasDirector>(builder);
        // std::shared_ptr<AbstractObject> obj = SolutionLoader::load<CarcasDirector>(builder);

        return myDirector->create();
    }
};

#endif // SOLUTIONLOADER_H
