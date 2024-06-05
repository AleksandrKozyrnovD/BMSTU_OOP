#include "point_array.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include "geometry.h"

void point_array_free(point_array_t &points)
{
    if (!points.array)
    {
        return;
    }
    free(points.array);
    points.count = 0;
}

/**
 * @brief Функция выделения памяти для массива точек
 *
 * @param[out] array Массив точек
 * @param[in] count Количество точек
 * @return errors_t Код ошибки
 */
static errors_t point_array_alloc(point_t **array, int count)
{
    if (!array || !count)
    {
        return ERR_PARAM;
    }

    *array = (point_t *)malloc(sizeof(struct point) * count);
    if (!(*array))
    {
        return ERR_MEM;
    }
    else
    {
        return EXIT_SUCCESSFUL;
    }
}

static errors_t field_point_array_read(point_t *array, int count, FILE *file)
{
    errors_t return_code = EXIT_SUCCESSFUL;
    for (point_t *ptr = array; !return_code && ptr < array + count; ++ptr)
    {
        return_code = point_read(*ptr, file);
    }

    return return_code;
}

errors_t point_array_read(point_array_t &points, FILE *file)
{
    if (!file)
    {
        return ERR_PARAM;
    }

    int count;
    if (fscanf(file, "%d", &count) != 1)
    {
        return ERR_IO;
    }

    if (count <= 0)
        return ERR_IO;

    errors_t return_code = point_array_alloc(&points.array, count); //При ошибке не выделит память
    if (!return_code)
    {
        return_code = field_point_array_read(points.array, count, file);
        if (return_code != EXIT_SUCCESSFUL) //Выделилась память, но не прочитались точки
        {
            free(points.array);
        }
        else
        {
            points.count = count;
        }
    }

    return return_code;
}

static void field_point_array_write(const point_t *array, int count, FILE *file)
{
    for (const point_t *ptr = array; ptr < array + count; ++ptr)
    {
        point_write(*ptr, file);
    }
}

errors_t point_array_write(FILE *file, const point_array_t &points)
{
    if (!file)
    {
        return ERR_PARAM;
    }

    fprintf(file, "%zu\n", points.count);
    field_point_array_write(points.array, points.count, file);

    return EXIT_SUCCESSFUL;
}

static void field_point_array_move(point_t *array, int count, const move_t &move)
{
    for (point_t *ptr = array; ptr < array + count; ++ptr)
    {
        point_move(*ptr, move);
    }
}

errors_t point_array_move(point_array_t &points, const move_t &move)
{
    if (!points.array)
    {
        return ERR_PARAM;
    }

    field_point_array_move(points.array, points.count, move);

    return EXIT_SUCCESSFUL;
}

static void field_point_array_scale(point_t *array, int count, const scale_t &scale)
{
    for (point_t *ptr = array; ptr < array + count; ++ptr)
    {
        point_scale(*ptr, scale);
    }
}

errors_t point_array_scale(point_array_t &points, const scale_t &scale)
{
    if (!points.array)
    {
        return ERR_PARAM;
    }

    field_point_array_scale(points.array, points.count, scale);

    return EXIT_SUCCESSFUL;
}

static void field_point_array_rotate(point_t *array, int count, const rotate_t &rotate)
{
    for (point_t *ptr = array; ptr < array + count; ++ptr)
    {
        point_rotate(*ptr, rotate);
    }
}

errors_t point_array_rotate(point_array_t &points, const rotate_t &rotate)
{
    if (!points.array)
    {
        return ERR_PARAM;
    }

    field_point_array_rotate(points.array, points.count, rotate);

    return EXIT_SUCCESSFUL;
}

point_array_t point_array_init(void)
{
    point_array_t array;
    array.array = NULL;
    array.count = 0;

    return array;
}
