#include "basecommand.h"

BaseCommand::BaseCommand() {}

void BaseCommand::SetFacade(const Facade& facade)
{
    this->proxy.draw = facade.SolDraw;
    this->proxy.scene = facade.SolScene;
    this->proxy.loader = facade.SolLoader;
    this->proxy.transform = facade.SolTransform;
}
