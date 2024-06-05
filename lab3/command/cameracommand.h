#ifndef CAMERACOMMAND_H
#define CAMERACOMMAND_H

#include "basecommand.h"

class CameraCommand : public BaseCommand {};

class CameraAddCommand : public CameraCommand
{
    using Action = void (SolutionScene::*)(std::shared_ptr<AbstractObject>);
public:
    CameraAddCommand() = default;
    explicit CameraAddCommand(std::shared_ptr<AbstractObject> camera);
    ~CameraAddCommand() = default;

    void execute() override;

private:
    Action method;
    std::shared_ptr<AbstractObject> camera;
};

class CameraRemoveCommand : public CameraCommand
{
    using Action = void (SolutionScene::*)(size_t);
public:
    CameraRemoveCommand() = default;
    explicit CameraRemoveCommand(size_t id);
    ~CameraRemoveCommand() = default;

    void execute() override;

private:
    Action method;
    size_t id;
};

class CameraSetCommand : public CameraCommand
{
    using Action = void (SolutionScene::*)(size_t);
public:
    CameraSetCommand() = default;
    explicit CameraSetCommand(size_t id);
    ~CameraSetCommand() = default;

    void execute() override;

private:
    Action method;
    size_t id;
};

class CameraGetCommand : public CameraCommand
{
    using Action = std::shared_ptr<Camera> (SolutionScene::*)();
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
