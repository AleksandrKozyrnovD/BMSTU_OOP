#include "drawer.h"

errors_t scene_clear(const view_scene_t &scene)
{
    if (!scene.scene)
    {
        return ERR_UNEXPECTED;
    }

    scene.scene->clear();

    return EXIT_SUCCESSFUL;
}

static errors_t check_ids(size_t count, size_t id_a, size_t id_b)
{
    if (id_a > count || id_b > count)
    {
        return ERR_PARAM;
    }

    return EXIT_SUCCESSFUL;
}

static g_line_t get_gline(const point_t *array, size_t id_a, size_t id_b)
{
    g_line_t line;

    line.A = array[id_a];
    line.B = array[id_b];

    return line;
}

/**
 * @brief Функция для получения графической линии из массива точек
 * 
 * @param[out] gline Графическая линия
 * @param[in] array Массив точек
 * @param[in] line Линия, соединяющая 2 точки
 * @return g_line_t Графическая линия
 */
static errors_t get_line(g_line_t &gline, const point_array_t &array, const line_t &line)
{
    errors_t return_code = check_ids(array.count, line.id_a, line.id_b);
    if (!return_code)
    {
        gline = get_gline(array.array, line.id_a, line.id_b);
    }

    return return_code;
}

static void draw_points(const view_scene_t &scene, const point_t &A, const point_t &B)
{
    //Цвет передавать как явный параметр
    scene.scene->addLine(A.x, A.y, B.x, B.y, scene.color);
}
/**
 * @brief Функция для рисования графической линии
 * 
 * @param[in] scene Сцена
 * @param[in] A Точка А
 * @param[in] B Точка B
 * @return errors_t Код ошибки 
 */
static errors_t draw_line(const view_scene_t &scene, const g_line_t &line)
{
    if (!scene.scene)
    {
        return ERR_UNEXPECTED;
    }

    draw_points(scene, line.A, line.B);

    return EXIT_SUCCESSFUL;
}

/**
 * @brief Функция для рисования графических линий
 * 
 * @param[in] scene Сцена
 * @param[in] points Массив точек
 * @param[in] lines Массив линий
 * @return errors_t Код ошибки
 */
static errors_t draw_lines(const view_scene_t &scene, const point_array_t &points, const line_array_t &lines)
{
    if (!scene.scene)
    {
        return ERR_UNEXPECTED;
    }

    if (!points.array || !points.count || !lines.array || !lines.count)
    {
        return ERR_IO;
    }

    g_line_t drawing_line;
    errors_t return_code = EXIT_SUCCESSFUL;

    for (line_t *line = lines.array; line < lines.array + lines.count && !return_code; ++line)
    {
        // drawing_line = get_line(points.array, *line); //А если таких двух точек не будет??? Код ошибки!!!
        return_code = get_line(drawing_line, points, *line);
        if (!return_code)
        {
            return_code = draw_line(scene, drawing_line);
        }
    }

    return return_code;
}

/**
 * @brief Функция для рисования фигуры
 * 
 * @param[in] scene Сцена
 * @param[in] figure Фигура
 * @return errors_t 
 */
errors_t scene_draw_figure(const view_scene_t &scene, const figure_t &figure)
{
    errors_t return_code = scene_clear(scene);
    if (return_code)
    {
        return return_code;
    }

    return draw_lines(scene, figure.points, figure.lines);
}
