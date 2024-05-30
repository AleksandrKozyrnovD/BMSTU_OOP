#include "modelcommand.h"
// #include "../builder/carcasbuilder.h"
// #include "../loader/filereader.h"
// #include "../builder/carcasdirector.h"
#include "../modelvisitor/rotatevisitor.h"
#include "../modelvisitor/movevisitor.h"
#include "../modelvisitor/scalevisitor.h"

// ModelCommand::ModelCommand() {}


ModelLoadCarcas::ModelLoadCarcas(std::shared_ptr<AbstractObject>& obj, const std::string& filename)
    : obj(obj), filename(filename)
{
    method = &SolutionLoader::load_from_simple_file;
}


void ModelLoadCarcas::execute()
{
    this->obj = ((*(this->proxy.loader)).*method)(this->filename);
}

ModelAddCarcas::ModelAddCarcas(std::shared_ptr<AbstractObject> obj)
    : obj(obj)
{
    this->method = &SolutionScene::add_object;
}


void ModelAddCarcas::execute()
{
    ((*(this->proxy.scene)).*method)(this->obj);
}

ModelRemoveCommand::ModelRemoveCommand(const int& number)
    : what_number_do_you_want_to_delete(number)
{
    method = &SolutionScene::remove_object;
}

void ModelRemoveCommand::execute()
{
    ((*(this->proxy.scene)).*method)(this->what_number_do_you_want_to_delete);
}

ModelGetCommand::ModelGetCommand(std::shared_ptr<AbstractObject>& object, int id)
    : object(object), id(id)
{
    method = &SolutionScene::get_object;
}

void ModelGetCommand::execute()
{
    this->object = ((*(this->proxy.scene)).*method)(this->id);
    // this->object = this->proxy.scene->get_scene()->get_models().at(index);
}

ModelsGetCommand::ModelsGetCommand(std::shared_ptr<AbstractObject>& object)
    : object(object)
{}

void ModelsGetCommand::execute()
{
    this->object = std::make_shared<CompositeObject>(this->proxy.scene->get_scene()->get_models());
}

ModelTransformCommand::ModelTransformCommand(std::shared_ptr<AbstractObject> obj)
    : obj(obj)
{
    method = &SolutionTransform::transform;
}

void ModelTransformCommand::execute()
{
    ((*(this->proxy.transform)).*method)(this->obj);
}


MakeMoveCommand::MakeMoveCommand(double x, double y, double z)
    : x(x), y(y), z(z)
{
    method = &SolutionTransform::set_visitor<MoveVisitor>;
}

void MakeMoveCommand::execute()
{
    ((*(this->proxy.transform)).*method)(this->x, this->y, this->z);
}

MakeRotateCommand::MakeRotateCommand(double x, double y, double z)
    : x(x), y(y), z(z)
{
    method = &SolutionTransform::set_visitor<RotateVisitor>;
}

void MakeRotateCommand::execute()
{
    ((*(this->proxy.transform)).*method)(this->x, this->y, this->z);
}

MakeScaleCommand::MakeScaleCommand(double x, double y, double z)
    : x(x), y(y), z(z)
{
    method = &SolutionTransform::set_visitor<ScaleVisitor>;
}

void MakeScaleCommand::execute()
{
    ((*(this->proxy.transform)).*method)(this->x, this->y, this->z);
}
