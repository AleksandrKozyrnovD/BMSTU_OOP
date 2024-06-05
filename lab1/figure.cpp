#include "figure.h"
// #include "string.h"
// #include "errt.h"
// #include "line.h"
// #include "point.h"

figure_t figure_init(void)
{
    figure_t figure;

    figure.points = point_array_init();
    figure.lines = line_array_init();

    return figure;
}

void figure_free(figure_t &figure)
{
    point_array_free(figure.points);
    line_array_free(figure.lines);
}

/**
 * @brief Функция считывания графических данных из файла
 *
 * @param[out] figure Структура фигуры
 * @param[in] file Указатель на файл
 * @return errors_t Код ошибки
 */
static errors_t figure_read_file(figure_t &figure, FILE *file)
{
    if (!file)
    {
        return ERR_PARAM;
    }

    errors_t return_code = point_array_read(figure.points, file);

    if (!return_code)
    {
        return_code = line_array_read(figure.lines, file);
        if (return_code != EXIT_SUCCESSFUL) //Выделилась память только на точки, но не на линии
        {
            point_array_free(figure.points);
        }
    }

    return return_code;
}

/**
 * @brief Функция записи графических данных в файл
 * 
 * @param[in] file Указатель на файл
 * @param[in] figure Структура фигуры
 * @return errors_t Код ошибки
 */
static errors_t figure_write_file(FILE *file, const figure_t &figure)
{
    if (!file)
    {
        return ERR_PARAM;
    }

    errors_t return_code = point_array_write(file, figure.points);
    if (!return_code)
    {
        return_code = line_array_write(file, figure.lines);
    }

    return return_code;
}

errors_t figure_load(figure_t &figure, const char *filename)
{
    if (!filename || !strlen(filename))
    {
        return ERR_PARAM;
    }

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        return ERR_UNEXPECTED;
    }

    figure_t tmp;
    errors_t return_code = figure_read_file(tmp, file);
    fclose(file);

    if (!return_code) //Не ошибка
    {
        figure_free(figure);
        figure = tmp;
    }

    return return_code;
}

errors_t figure_save(const figure_t &figure, const char *filename)
{
    if (!filename || !strlen(filename))
    {
        return ERR_PARAM;
    }

    FILE *file = fopen(filename, "w");
    if (!file)
    {
        return ERR_UNEXPECTED;
    }

    errors_t return_code = figure_write_file(file, figure);
    fclose(file);

    return return_code;
}


errors_t figure_move(figure_t &figure, const move_t &move)
{
    return point_array_move(figure.points, move);
}


/**
 * @brief Функция для перемещения фигуры в центр координат
 * 
 * @param[in,out] figure Структура фигуры
 * @param[in] center Центр фигуры (Заданный)
 * @return errors_t Код ошибки
 */
static errors_t points_move_center(point_array_t &points, const point_t &center)
{
    move_t move;

    move.dx = -center.x;
    move.dy = -center.y;
    move.dz = -center.z;

    return point_array_move(points, move);
}

/**
 * @brief Функция для перемещения фигуры в свой центр координат
 * 
 * @param[in,out] figure Структура фигуры
 * @param[in] center Центр фигуры (Заданный)
 * @return errors_t Код ошибки
 */
static errors_t points_move_old_center(point_array_t &points, const point_t &center)
{
    move_t move;

    move.dx = center.x;
    move.dy = center.y;
    move.dz = center.z;

    return point_array_move(points, move);
}

errors_t figure_scale(figure_t &figure, const point_t &center, const scale_t &scale)
{
    errors_t return_code = points_move_center(figure.points, center);

    if (!return_code)
    {
        return_code = point_array_scale(figure.points, scale);
        if (!return_code)
        {
            return_code = points_move_old_center(figure.points, center);
        }
    }
    return return_code;
}

errors_t figure_rotate(figure_t &figure, const point_t &center, const rotate_t &rotate)
{
    errors_t return_code = points_move_center(figure.points, center);

    if (!return_code)
    {
        return_code = point_array_rotate(figure.points, rotate);
        if (!return_code)
        {
            return_code = points_move_old_center(figure.points, center);
        }
    }
    return return_code;
}

