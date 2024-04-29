#ifndef DOMEN_H
#define DOMEN_H

#include "errt.h"
#include "drawer.h"
#include "figure.h"

enum aaction
{
    // INIT = 0,
    MOVE,
    ROTATE,
    SCALE,
    SAVE,
    LOAD,
    FREE,
    DRAW
};

using e_action_t = enum aaction;


struct _action
{
    e_action_t action;
    point_t center;
    view_scene_t scene;
    union
    {
        const char *filename;
        // view_scene_t scene; //Не разрешает в объединение записать такую структуру!
        move_t move;
        scale_t scale;
        rotate_t rotate;
    };
};

using action_t = struct _action;

errors_t do_action(action_t &action);

#endif // DOMEN_H
