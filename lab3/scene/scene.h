#ifndef SCENE_H
#define SCENE_H

#include "../object/abstractobject.h"
#include "../object/camera/camera.h"
#include <list>

class Scene
{
public:
    Scene();
    ~Scene() = default;

    bool add_model(const std::shared_ptr<AbstractObject>& object);
    bool remove_model(int index);

    bool add_camera(const std::shared_ptr<Camera>& camera);
    bool remove_camera(int index);

    std::vector<std::shared_ptr<AbstractObject>>& get_models();
    // std::list<std::vector<std::shared_ptr<AbstractObject>>::iterator>& get_cameras();
    std::vector<std::shared_ptr<Camera>>& get_cameras();

    std::shared_ptr<AbstractObject> get_object(int id);

protected:
    std::vector<std::shared_ptr<Camera>> cameras = {}; //хранить вектор итераторов на камеры
    // CompositeObject objects; //abstract ptr std::vector

    // std::list<std::vector<std::shared_ptr<AbstractObject>>::iterator> cameras;

    std::vector<std::shared_ptr<AbstractObject>> objects;
};

#endif // SCENE_H
