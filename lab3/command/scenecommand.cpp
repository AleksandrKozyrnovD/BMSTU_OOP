#include "scenecommand.h"


void SceneClearCommand::execute()
{
    this->proxy.scene->clear_scene();
}
