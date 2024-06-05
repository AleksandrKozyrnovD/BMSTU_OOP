#ifndef SOLUTIONLOADER_H
#define SOLUTIONLOADER_H

#include "basesolution.h"
#include "../object/abstractobject.h"
#include "../loader/loader.h"
#include "../builder/carcasdirector.h"
#include "../loader/filereader.h"
#include "../loader/binaryreader.h"
#include "../builder/carcasbuilder.h"
#include "../builder/matrixbuilder.h"

// class binary_id {};

// class simple_id {};




class SolutionLoader : public BaseSolution
{
public:
    SolutionLoader();
    ~SolutionLoader() = default;

    template<typename builder>
        requires std::derived_from<builder, BaseCarcasBuilder> && std::constructible_from<builder, std::shared_ptr<AbstractReader>>
    std::shared_ptr<AbstractObject> load_from_file(const std::string& filename)
    {
        std::shared_ptr<AbstractReader> reader = std::make_shared<FileReader>(filename);
        std::shared_ptr<BaseCarcasBuilder> _builder = std::make_shared<builder>(reader);
        std::shared_ptr<BaseDirector> myDirector = DirectorCreator::create<CarcasDirector>(_builder);

        return myDirector->create();
    }
    template<typename builder>
        requires std::derived_from<builder, BaseCarcasBuilder> && std::constructible_from<builder, std::shared_ptr<AbstractReader>>
    std::shared_ptr<AbstractObject> load_from_binary(const std::string& filename)
    {
        std::shared_ptr<AbstractReader> reader = std::make_shared<BinaryReader>(filename);
        std::shared_ptr<BaseCarcasBuilder> _builder = std::make_shared<builder>(reader);
        std::shared_ptr<BaseDirector> myDirector = DirectorCreator::create<CarcasDirector>(_builder);

        return myDirector->create();
    }
};

#endif // SOLUTIONLOADER_H
