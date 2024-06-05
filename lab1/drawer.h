#ifndef DRAWER_H
#define DRAWER_H

#include <QGraphicsView>
#include "figure.h"

//Структура для отрисовки на сцене
struct graphic_line
{
    point_t A, B;
};

//Структура сцены
struct viewscene
{
    QGraphicsScene *scene;
    //double width, height;
    QPen color;
};

using view_scene_t = struct viewscene;

using g_line_t = struct graphic_line;

/**
 * @brief Функция очистки сцены
 * 
 * @param[in] scene Сцена
 * @return errors_t Код ошибки
 */
errors_t scene_clear(const view_scene_t &scene);

/**
 * @brief Функция отрисовки фигуры на сцене
 * 
 * @param[in] scene Сцена
 * @param[in] figure Фигура
 * @return errors_t Код ошибки
 */
errors_t scene_draw_figure(const view_scene_t &scene, const figure_t &figure);

#endif

