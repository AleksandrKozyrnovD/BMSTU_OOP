#include "facade.h"
#include "../command/basecommand.h"

Facade::Facade() { /*Добавить инициализацию по стандарту*/}

Facade::Facade(SolutionDraw d, SolutionLoader l, SolutionTransform t, SolutionScene s)
    : SolDraw(std::make_shared<SolutionDraw>(d))
    , SolLoader(std::make_shared<SolutionLoader>(l))
    , SolTransform(std::make_shared<SolutionTransform>(t))
    , SolScene(std::make_shared<SolutionScene>(s))
{}

void Facade::execute(BaseCommand& command)
{
    command.SetFacade(*this);
    command.execute();
}
