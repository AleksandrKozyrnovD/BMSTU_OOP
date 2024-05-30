#ifndef FACADE_H
#define FACADE_H

#include "../solution/solutiondraw.h"
#include "../solution/solutionloader.h"
#include "../solution/solutionscene.h"
#include "../solution/solutiontransform.h"

class BaseCommand;

class Facade
{
    friend class BaseCommand;
public:
    Facade();
    Facade(SolutionDraw d, SolutionLoader l, SolutionTransform t, SolutionScene s);

    void execute(BaseCommand& command);

protected:
    std::shared_ptr<SolutionDraw> SolDraw;
    std::shared_ptr<SolutionLoader> SolLoader;
    std::shared_ptr<SolutionTransform> SolTransform;
    std::shared_ptr<SolutionScene> SolScene;
};

#endif // FACADE_H
