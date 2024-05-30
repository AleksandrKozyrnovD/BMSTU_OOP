#include "scene.h"

Scene::Scene() {}

bool Scene::add_model(const std::shared_ptr<AbstractObject>& object)
{
    this->objects.push_back(object);

    return true;
}

bool Scene::remove_model(int index)
{
    if (index < 0)
    {
        return false;
    }

    auto iter = this->objects.begin();
    std::advance(iter, index);
    this->objects.erase(iter);

    return true;
}


bool Scene::add_camera(const std::shared_ptr<Camera>& camera)
{
    this->add_model(camera);

    this->cameras.push_back(camera);
    // auto prev = this->objects.begin();
    // auto iter = prev;
    // for (; iter != this->objects.end(); ++iter)
    // {
    //     prev = iter;
    // }
    // this->cameras.push_back(prev);

    return true;
}


bool Scene::remove_camera(int index)
{
    auto iter = this->cameras.begin();

    std::advance(iter, index);

    this->cameras.erase(iter);

    // this->remove_model(index);

    return true;
}

std::vector<std::shared_ptr<AbstractObject>>& Scene::get_models()
{
    return this->objects;
}

// std::list<std::vector<std::shared_ptr<AbstractObject>>::iterator>& Scene::get_cameras()
std::vector<std::shared_ptr<Camera>>& Scene::get_cameras()
{
    return this->cameras;
}

std::shared_ptr<AbstractObject> Scene::get_object(int id)
{
    std::shared_ptr<AbstractObject> obj;
    for (auto& elem : this->objects)
    {
        if (elem->get_id() == id)
        {
            obj = elem;
        }
    }

    return obj;
}
