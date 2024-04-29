// #include <stdio.h>
// #include "stdlib.h"
#include "line_array.h"


void line_array_free(line_array_t &lines)
{
    if (!lines.array)
    {
        return;
    }
    free(lines.array);
    lines.count = 0;
}

/**
 * @brief Функция выделения памяти для массива линий
 * 
 * @param[out] array Массив линий
 * @param[in] count Количество линий
 * @return errors_t Код ошибки 
 */
static errors_t line_array_alloc(line_t **array, int count)
{
    if (!array || !count)
    {
        return ERR_PARAM;
    }

    *array = (line_t *)malloc(sizeof(struct line) * count);
    if (!(*array))
    {
        return ERR_MEM;
    }
    else
    {
        return EXIT_SUCCESSFUL;
    }
}

static errors_t field_line_array_read(line_t *array, int count, FILE *file)
{
    errors_t return_code = EXIT_SUCCESSFUL;

    for (line_t *ptr = array; !return_code && ptr < array + count; ++ptr)
    {
        return_code = line_read(*ptr, file);
    }

    return return_code;
}

errors_t line_array_read(line_array_t &lines, FILE *file)
{
    if (!file || !lines.array)
    {
        return ERR_PARAM;
    }

    int count;
    if (fscanf(file, "%d", &count) != 1)
    {
        return ERR_IO;
    }

    if (count <= 0)
    {
        return ERR_IO;
    }

    errors_t return_code = line_array_alloc(&lines.array, count); //Память не выделится при ошибке!

    if (!return_code)
    {
        return_code = field_line_array_read(lines.array, count, file);
        if (!return_code)
        {
            lines.count = count;
        }
        else //Выделилась память, но ошибка считывания
        {
            free(lines.array);
        }
    }

    return return_code;
}


static void field_line_array_write(const line_t *array, int count, FILE *file)
{
    for (const line_t *ptr = array; ptr < array + count; ++ptr)
    {
        line_write(file, *ptr);
    }
}

errors_t line_array_write(FILE *file, const line_array_t &lines)
{
    if (!file)
    {
        return ERR_PARAM;
    }

    fprintf(file, "%zu\n", lines.count);
    field_line_array_write(lines.array, lines.count, file);

    return EXIT_SUCCESSFUL;
}

line_array_t line_array_init(void)
{
    line_array_t array;
    array.array = NULL;
    array.count = 0;

    return array;
}

