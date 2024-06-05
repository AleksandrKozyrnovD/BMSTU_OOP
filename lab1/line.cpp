#include "line.h"

void line_write(FILE *file, const line_t &line)
{
    if (!file)
    {
        return;
    }
    fprintf(file, "%zu %zu\n", line.id_a, line.id_b);
}

errors_t line_read(line_t &line, FILE *file)
{
    if (!file)
    {
        return ERR_PARAM;
    }

    if (fscanf(file, "%zu%zu", &line.id_a, &line.id_b) != 2)
    {
        return ERR_IO;
    }

    if (line.id_a == line.id_b)
    {
        return ERR_IO;
    }

    return EXIT_SUCCESSFUL;
}

