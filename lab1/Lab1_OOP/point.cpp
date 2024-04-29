#include "point.h"


errors_t point_read(point_t &point, FILE *file)
{
    if (!file)
    {
        return ERR_PARAM;
    }
    if (fscanf(file, "%lf%lf%lf", &point.x, &point.y, &point.z) != 3)
    {
        return ERR_IO;
    }

    return EXIT_SUCCESSFUL;
}

void point_write(const point_t &point, FILE *file)
{
    if (!file)
    {
        return;
    }

    fprintf(file, "%lf %lf %lf\n", point.x, point.y, point.z);
}


//=//==============================================//=//

/**
 * @brief Функция поворота точки вокруг оси OX относительно начала координат
 *
 * @param[in,out] point Структура точки
 * @param[in] angle Угол поворота в градусах
 */
static inline void turn_around_x_axis(point_t &point, double angle)
{
    double cos = cosinus(angle);
    double sin = sinus(angle);

    double copy_y = point.y;

    point.y = point.y * cos + point.z * sin;
    point.z = -copy_y * sin + point.z * cos;
}

/**
 * @brief Функция поворота точки вокруг оси OY относительно начала координат
 *
 * @param[in,out] point Структура точки
 * @param[in] angle Угол поворота в градусах
 */
static inline void turn_around_y_axis(point_t &point, double angle)
{
    double cos = cosinus(angle);
    double sin = sinus(angle);

    double copy_x = point.x;

    point.x = point.x * cos + point.z * sin;
    point.z = -copy_x * sin + point.z * cos;
}

/**
 * @brief Функция поворота точки вокруг оси OZ относительно начала координат
 *
 * @param[in,out] point Структура точки
 * @param[in] angle Угол поворота в градусах
 */
static inline void turn_around_z_axis(point_t &point, double angle)
{
    double cos = cosinus(angle);
    double sin = sinus(angle);

    double copy_x = point.x;

    point.x = point.x * cos + point.y * sin;
    point.y = -copy_x * sin + point.y * cos;
}

//=//==============================================//=//

void point_move(point_t &point, const move_t &move)
{
    point.x += move.dx;
    point.y += move.dy;
    point.z += move.dz;
}

void point_scale(point_t &point, const scale_t &scale)
{
    point.x *= scale.kz;
    point.y *= scale.ky;
    point.z *= scale.kz;
}

void point_rotate(point_t &point, const rotate_t &rotate)
{
    turn_around_x_axis(point, rotate.ax);
    turn_around_y_axis(point, rotate.ay);
    turn_around_z_axis(point, rotate.az);
}

