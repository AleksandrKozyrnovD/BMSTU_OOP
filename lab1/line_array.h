#ifndef LINE_ARRAY_H
#define LINE_ARRAY_H

#include <stdio.h>
#include "line.h"
#include "errt.h"

#include <stdlib.h>
#include <stddef.h>





//Структура массива линий
struct line_array
{
    size_t count;
    struct line *array; //Массив отрезков
};

using line_array_t = struct line_array;


/**
 * @brief Функция считывания линий из файла
 *
 * @param[out] lines Структура массива линий
 * @param[in] file Указатель на файл
 * @return errors_t Код ошибки (enumerate)
 */
errors_t line_array_read(line_array_t &lines, FILE *file);

/**
 * @brief Функция записи массива линий в файл
 *
 * @param[in] file Указатель на файл
 * @param[in] lines Структура массива линий
 * @return errors_t Код ошибки (enumerate)
 */
errors_t line_array_write(FILE *file, const line_array_t &lines);

/**
 * @brief Функция освобождения памяти
 * 
 * @param[in] lines Структура массива линий 
 */
void line_array_free(line_array_t &lines);

/**
 * @brief Функция первичной инициализации структуры массива линий
 *
 * @return figure_t Начальная инициализированная структура массива линий
 */
line_array_t line_array_init(void);



#endif
