#include "scenecommand.h"


void SceneClearCommand::execute()
{
    int size = this->proxy.scene->get_scene()->get_models().size();

    for (int i = size - 1; i > 0; i--)
    {
        this->proxy.scene->get_scene()->remove_model(i);
    }
}
