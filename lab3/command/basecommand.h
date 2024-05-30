#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include "../facade/facade.h"

struct FacadeProxy
{
    std::shared_ptr<SolutionDraw> draw;
    std::shared_ptr<SolutionScene> scene;
    std::shared_ptr<SolutionTransform> transform;
    std::shared_ptr<SolutionLoader> loader;
};


class BaseCommand
{
public:
    BaseCommand();
    virtual ~BaseCommand() = default;

    virtual void execute() = 0;

    void SetFacade(const Facade& facade);

protected:
    FacadeProxy proxy;
};


#endif // BASECOMMAND_H
