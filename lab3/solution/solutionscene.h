#ifndef SOLUTIONSCENE_H
#define SOLUTIONSCENE_H

#include "basesolution.h"
#include "../scene/scene.h"

class SolutionScene : public BaseSolution
{
public:
    SolutionScene();
    explicit SolutionScene(std::shared_ptr<Scene> scene);
    ~SolutionScene() = default;

    void add_camera(std::shared_ptr<AbstractObject> camera);
    void set_scene(std::shared_ptr<Scene> scene);
    std::shared_ptr<Scene> get_scene();

    void set_camera(std::shared_ptr<Camera> camera);

    void add_object(std::shared_ptr<AbstractObject> object);
    std::vector<std::shared_ptr<AbstractObject>> get_objects();
    std::shared_ptr<AbstractObject> get_object(std::size_t id);
    std::vector<std::size_t> get_object_ids();
    void remove_object(std::size_t id);
    void make_composite(std::vector<size_t> ids);

    // void AddCamera(const Point& pos);
    std::vector<std::shared_ptr<AbstractObject>> get_cameras();
    std::vector<std::size_t> get_camera_ids();
    std::shared_ptr<Camera> get_camera(std::size_t id);
    std::shared_ptr<Camera> get_main_camera();
    void remove_camera(std::size_t id);
    void set_camera(std::size_t id);

    void clear_scene();

protected:
    std::shared_ptr<Scene> scene;
    std::shared_ptr<Camera> camera;
};

#endif // SOLUTIONSCENE_H
