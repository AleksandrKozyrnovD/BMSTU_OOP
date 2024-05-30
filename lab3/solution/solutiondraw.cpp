#include "solutiondraw.h"

SolutionDraw::SolutionDraw() {}

SolutionDraw::SolutionDraw(std::shared_ptr<DrawVisitor> visitor)
    : visitor(visitor)
{}


void SolutionDraw::set_visitor(std::shared_ptr<DrawVisitor> visitor)
{
    this->visitor = visitor;
}

void SolutionDraw::set_camera(std::shared_ptr<Camera> camera)
{
    this->visitor->set_camera(camera);
}

void SolutionDraw::accept(std::shared_ptr<AbstractObject> obj)
{
    obj->accept(this->visitor);
}
