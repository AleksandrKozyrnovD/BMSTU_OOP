#ifndef LINE_H
#define LINE_H

#include <stddef.h>
#include <stdio.h>
#include "errt.h"

//Структура линии
struct line
{
    //Хранит индексы точек структуры point_array_t
    size_t id_a, id_b;
};

using line_t = struct line;

/**
 * @brief Функция записи линии в файл
 *
 * @param[in] file Указатель на файл
 * @param[in] line Структура линии
 */
void line_write(FILE *file, const line_t &line);

/**
 * @brief Функция считывания 1-й линии из файла
 *
 * @param[out] line Структура линии
 * @param[in] file Указатель на файл
 * @return errors_t Код ошибки
 */
errors_t line_read(line_t &line, FILE *file);

#endif // LINE_H
