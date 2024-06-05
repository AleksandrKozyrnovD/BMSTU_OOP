#ifndef POINT_ARRAY_H
#define POINT_ARRAY_H

#include "errt.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "point.h"
// #include "geometry.h"



//Структура массива точек
struct point_array
{
    size_t count;
    struct point *array; //Массив точек
};

using point_array_t = struct point_array;


/**
 * @brief Функция для чтения точек из файла
 *
 * @param[out] points Структура массива точек
 * @param[in] file Указатель на файл
 * @return errors_t Код ошибки (enumerate)
 */
errors_t point_array_read(point_array_t &points, FILE *file);

/**
 * @brief Функция для освобождения памяти из-под структуры массива точек
 * 
 * @param[in,out] points Структура массива точек 
 */
void point_array_free(point_array_t &points);

/**
 * @brief Функция первичной инициализации структуры массива точек
 *
 * @return figure_t Начальная инициализированная структура массива точек
 */
point_array_t point_array_init(void);


/**
 * @brief Функция для перемещения точек на dx, dy, dz
 * 
 * @param[in,out] points Структура массива точек 
 * @param[in] move Структура перемещения точки
 * @return errors_t Код ошибки (enumerate)
 */
errors_t point_array_move(point_array_t &points, const move_t &move);

/**
 * @brief Функция для масштабирования точек относительно начала координат
 * 
 * @param[in,out] points Структура массива точек
 * @param[in] scale Структура масштабирования точки
 * @return errors_t Код ошибки (enumerate)
 */
errors_t point_array_scale(point_array_t &points, const scale_t &scale);

/**
 * @brief Функция для поворота точек относительно начала координат
 * 
 * @param[in,out] points Структура массива точек
 * @param[in] rotate Структура поворота
 * @return errors_t Код ошибки (enumerate)
 */
errors_t point_array_rotate(point_array_t &points, const rotate_t &rotate);

/**
 * @brief Функция для записи точек в файл
 * 
 * @param[in] file Указатель на файл
 * @param[in] points Структура массива точек
 * @return errors_t Код ошибки (enumerate)
 */
errors_t point_array_write(FILE *file, const point_array_t &points);

#endif


