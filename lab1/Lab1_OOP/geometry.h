#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <math.h>

// #define PI 3.14159265358979323846

//Macros
#define radians(Ugol) ((Ugol) * M_PI / 180)

/**
 * @brief Косинус угла через градусы
 * 
 * @param[in] angle Угол в градусах
 * @return double Значение косинуса
 */
double cosinus(double angle);

/**
 * @brief Синус угла через градусы
 * 
 * @param[in] angle Угол в градусах
 * @return double Значение синуса
 */
double sinus(double angle);

#endif

