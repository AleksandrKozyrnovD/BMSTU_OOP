#ifndef CAMERACOMMAND_H
#define CAMERACOMMAND_H

#include "basecommand.h"

class CameraCommand : public BaseCommand {};

class CameraAddCommand : public CameraCommand
{
    using Action = void (SolutionScene::*)(std::shared_ptr<Camera>);
public:
    CameraAddCommand() = default;
    explicit CameraAddCommand(std::shared_ptr<Camera> camera);
    ~CameraAddCommand() = default;

    void execute() override;

private:
    Action method;
    std::shared_ptr<Camera> camera;
};

class CameraRemoveCommand : public CameraCommand
{
    using Action = void (SolutionScene::*)(int);
public:
    CameraRemoveCommand() = default;
    explicit CameraRemoveCommand(int number);
    ~CameraRemoveCommand() = default;

    void execute() override;

private:
    Action method;
    int number;
};

class CameraSetCommand : public CameraCommand
{
    using Action = void (SolutionScene::*)(int);
public:
    CameraSetCommand() = default;
    explicit CameraSetCommand(int id);
    ~CameraSetCommand() = default;

    void execute() override;

private:
    Action method;
    int id;
};

class CameraGetCommand : public CameraCommand
{
    using Action = std::shared_ptr<Camera>& (SolutionScene::*)();
public:
    CameraGetCommand() = delete;
    explicit CameraGetCommand(std::shared_ptr<Camera>& camera);
    ~CameraGetCommand() = default;

    void execute() override;

private:
    Action method;
    std::shared_ptr<Camera>& camera;
};


class CameraTransformCommand : public CameraCommand
{
    using Action = void (SolutionTransform::*)(std::shared_ptr<AbstractObject>&) const;
public:
    CameraTransformCommand() = delete;
    explicit CameraTransformCommand(std::shared_ptr<Camera>& camera);
    ~CameraTransformCommand() = default;

    void execute() override;

private:
    Action method;
    std::shared_ptr<Camera>& camera;
};



#endif // CAMERACOMMAND_H
