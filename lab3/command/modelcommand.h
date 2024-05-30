#ifndef MODELCOMMAND_H
#define MODELCOMMAND_H

#include "basecommand.h"
#include "../object/abstractobject.h"

class ModelCommand : public BaseCommand {};


class ModelLoadCarcas : public ModelCommand
{
    using Action = std::shared_ptr<AbstractObject> (SolutionLoader::*)(const std::string&);
public:
    ModelLoadCarcas() = delete;
    ModelLoadCarcas(std::shared_ptr<AbstractObject>& obj, const std::string& filename);
    ~ModelLoadCarcas() = default;

    void execute() override;

private:
    std::shared_ptr<AbstractObject>& obj;
    std::string filename;
    Action method;
};

class ModelAddCarcas : public ModelCommand
{
    using Action = void (SolutionScene::*)(std::shared_ptr<AbstractObject>&);
public:
    ModelAddCarcas() = default;
    explicit ModelAddCarcas(std::shared_ptr<AbstractObject> obj);
    ~ModelAddCarcas() = default;

    void execute() override;

private:
    std::shared_ptr<AbstractObject> obj;
    Action method;
};


class ModelRemoveCommand : public ModelCommand
{
    using Action = void (SolutionScene::*)(int);
public:
    ModelRemoveCommand() = default;
    explicit ModelRemoveCommand(const int& number);
    ~ModelRemoveCommand() = default;

    void execute() override;

private:
    int what_number_do_you_want_to_delete;
    Action method;
};

class ModelGetCommand : public ModelCommand
{
    using Action = std::shared_ptr<AbstractObject> (SolutionScene::*)(int);
public:
    ModelGetCommand() = delete;
    explicit ModelGetCommand(std::shared_ptr<AbstractObject>& object, int id);
    ~ModelGetCommand() = default;

    void execute() override;

protected:
    std::shared_ptr<AbstractObject>& object;
    int id;
    Action method;
};

class ModelsGetCommand : public ModelCommand
{
    using Action = std::vector<std::shared_ptr<AbstractObject>>& (SolutionScene::*)();
public:
    ModelsGetCommand() = delete;
    ModelsGetCommand(std::shared_ptr<AbstractObject>& object);
    ~ModelsGetCommand() = default;

    void execute() override;

protected:
    Action method;
    std::shared_ptr<AbstractObject>& object;
};

class ModelTransformCommand : public ModelCommand
{
    using Action = void (SolutionTransform::*)(std::shared_ptr<AbstractObject>& object) const;
public:
    ModelTransformCommand() = default;
    ModelTransformCommand(std::shared_ptr<AbstractObject> obj);
    ~ModelTransformCommand() = default;

    void execute() override;

private:
    Action method;
    std::shared_ptr<AbstractObject> obj;
};


class MakeMoveCommand : public ModelCommand
{
    using Action = void (SolutionTransform::*)(double, double, double);
public:
    MakeMoveCommand() = delete;
    MakeMoveCommand(double x, double y, double z);
    ~MakeMoveCommand() = default;

    void execute() override;

private:
    Action method;
    double x, y, z;
};

class MakeRotateCommand : public ModelCommand
{
    using Action = void (SolutionTransform::*)(double, double, double);
public:
    MakeRotateCommand() = delete;
    MakeRotateCommand(double x, double y, double z);
    ~MakeRotateCommand() = default;

    void execute() override;

private:
    Action method;
    double x, y, z;
};

class MakeScaleCommand : public ModelCommand
{
    using Action = void (SolutionTransform::*)(double, double, double);
public:
    MakeScaleCommand() = delete;
    MakeScaleCommand(double x, double y, double z);
    ~MakeScaleCommand() = default;

    void execute() override;

private:
    Action method;
    double x, y, z;
};

#endif // MODELCOMMAND_H
