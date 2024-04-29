#include "domen.h"


errors_t do_action(action_t &action)
{
    static figure_t figure = figure_init();

    errors_t rc = EXIT_SUCCESSFUL;

    switch (action.action)
    {
    case LOAD:
        rc = figure_load(figure, action.filename);
        break;
    case SAVE:
        rc = figure_save(figure, action.filename);
        break;
    case MOVE:
        rc = figure_move(figure, action.move);
        break;
    case SCALE:
        rc = figure_scale(figure, action.center, action.scale);
        break;
    case ROTATE:
        rc = figure_rotate(figure, action.center, action.rotate);
        break;
    case DRAW:
        rc = scene_draw_figure(action.scene, figure);
        break;
    case FREE:
        figure_free(figure);
        break;
    default:
        rc = ERR_UNEXPECTED;
    }

    return rc;
}
