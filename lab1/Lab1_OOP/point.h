#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include "geometry.h"
#include "errt.h"

//Структура точки
struct point
{
    double x, y, z;
};

//Структура перемещения
struct move
{
    double dx, dy, dz;
};

//Структура масштабирования
struct scale
{
    double kx, ky, kz;
};

//Структура поворота
struct rotate
{
    double ax, ay, az;
};

using move_t = struct move;
using scale_t = struct scale;
using rotate_t = struct rotate;

using point_t = struct point;

/**
 * @brief Функция считывания точки из файла
 *
 * @param[out] point Структура точки
 * @param[in] file Указатель на файл
 * @return errors_t Код ошибки
 */
errors_t point_read(point_t &point, FILE *file);

/**
 * @brief Функция записи точки в файл
 *
 * @param[in] file Указатель на файл
 * @param[in] point Структура точки
 */
void point_write(const point_t &point, FILE *file);

/**
 * @brief Функция перемещения точки
 *
 * @param[in,out] point Структура точки
 * @param[in] move Структура перемещения
 */
void point_move(point_t &point, const move_t &move);

/**
 * @brief Функция масштабирования относительно начала координат
 *
 * @param[in,out] point Структура точки
 * @param[in] scale Структура масштабирования
 */
void point_scale(point_t &point, const scale_t &scale);

/**
 * @brief Функция поворота точки относительно начала координат
 *
 * @param[in,out] point Структура точки
 * @param[in] rotate Структура поворота
 */
void point_rotate(point_t &point, const rotate_t &rotate);

#endif // POINT_H
