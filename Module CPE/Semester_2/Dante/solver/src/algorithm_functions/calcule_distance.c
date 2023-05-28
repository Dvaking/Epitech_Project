/*
** EPITECH PROJECT, 2023
** calcul_distance
** File description:
** calcul the distance between two point in 2D space
*/

#include <math.h>
#include "open_and_closed_lists.h"

int distance(point_s point1, point_s point2)
{
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}
