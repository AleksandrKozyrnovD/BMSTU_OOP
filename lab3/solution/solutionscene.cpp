#include "solutionscene.h"

SolutionScene::SolutionScene() {}

SolutionScene::SolutionScene(std::shared_ptr<Scene> scene)
    : scene(scene)
{}


std::shared_ptr<Scene> SolutionScene::get_scene()
{
    return this->scene;
}

void SolutionScene::set_scene(std::shared_ptr<Scene> scene)
{
    this->scene = scene;
}

std::shared_ptr<Camera>& SolutionScene::get_camera()
{
    return this->camera;
}

void SolutionScene::set_camera(std::shared_ptr<Camera> camera)
{
    this->camera = camera;
}

void SolutionScene::set_camera(int id)
{
    std::shared_ptr<Camera> obj = this->get_scene()->get_cameras().at(id);
    this->set_camera(obj);
}

void SolutionScene::add_camera(std::shared_ptr<Camera> camera)
{
    this->scene->add_camera(camera);
}

void SolutionScene::add_object(std::shared_ptr<AbstractObject>& object)
{
    this->scene->add_model(object);
}

std::vector<std::shared_ptr<AbstractObject>>& SolutionScene::get_objects()
{
    return this->scene->get_models();
}

void SolutionScene::remove_object(int id)
{
    this->scene->remove_model(id);
}

void SolutionScene::remove_camera(int id)
{
    this->scene->remove_camera(id);
}

std::shared_ptr<AbstractObject> SolutionScene::get_object(int id)
{
    return this->scene->get_object(id);
}
