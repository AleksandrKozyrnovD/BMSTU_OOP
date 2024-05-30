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

    std::shared_ptr<Scene> get_scene();
    void set_scene(std::shared_ptr<Scene> scene);

    std::shared_ptr<Camera>& get_camera();
    void set_camera(std::shared_ptr<Camera> camera);
    void set_camera(int id);


    void add_camera(std::shared_ptr<Camera> camera);
    void add_object(std::shared_ptr<AbstractObject>& object);

    std::vector<std::shared_ptr<AbstractObject>>& get_objects();
    void remove_object(int id);
    void remove_camera(int id);
    std::shared_ptr<AbstractObject> get_object(int id);

protected:
    std::shared_ptr<Scene> scene;
    std::shared_ptr<Camera> camera;
};

#endif // SOLUTIONSCENE_H
