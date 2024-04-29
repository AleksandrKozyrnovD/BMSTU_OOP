#ifndef FIGURE_H
#define FIGURE_H

#include <stdio.h>
#include "errt.h"
#include "line_array.h"
#include "point_array.h"

#include "string.h"

//Структура геометрического тела
struct figure
{
    point_array_t points;
    line_array_t lines;
};

// typedef struct figure figure_t;

using figure_t = struct figure;

/**
 * @brief Функция первичной инициализации структуры фигуры
 * 
 * @return figure_t Начальная инициализированная структура
 */
figure_t figure_init(void);

/**
 * @brief Функция освобождения памяти из-под структуры
 * 
 * @param[in] figure Структура фигуры 
 */
void figure_free(figure_t &figure);

/**
 * @brief Функция загрузки (чтения) фигуры из файла
 *
 * @param[out] figure Структура фигуры
 * @param[in] filename Имя файла
 * @return errors_t Код ошибки (enumerate)
 */
errors_t figure_load(figure_t &figure, const char *filename);

/**
 * @brief Функция сохранения (записи) фигуры в файл
 * 
 * @param[in] filename Имя файла
 * @param[in] figure Структура фигуры
 * @return errors_t Код ошибки (enumerate)
 */
errors_t figure_save(const figure_t &figure, const char *filename);

/**
 * @brief Функция перемещения фигуры
 * 
 * @param[in,out] figure Структура фигуры
 * @param[in] move Структура перемещения
 * @return errors_t Код ошибки (enumerate)
 */
errors_t figure_move(figure_t &figure, const move_t &move);

/**
 * @brief Функция масштабирования фигуры
 * 
 * @param[in,out] figure Структура фигуры
 * @param[in] center Центр масштабирования
 * @param[in] scale Структура масштабирования
 * @return errors_t Код ошибки (enumerate)
 */
errors_t figure_scale(figure_t &figure, const point_t &center, const scale_t &scale);

/**
 * @brief Функция поворота фигуры
 * 
 * @param[in,out] figure Структура фигуры
 * @param[in] center Центр поворота
 * @param[in] rotate Структура поворота
 * @return errors_t Код ошибки (enumerate)
 */
errors_t figure_rotate(figure_t &figure, const point_t &center, const rotate_t &rotate);

#endif

