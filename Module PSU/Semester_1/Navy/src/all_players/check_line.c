/*
** EPITECH PROJECT, 2023
** check_line
** File description:
** check_line
*/
#include "proto.h"
#include "struct.h"

int check_line(t_player *p1)
{
    if (p1->i2 != p1->i2f && p1->x2 != p1->x2f)
        return 84;
    if (p1->i3 != p1->i3f && p1->x3 != p1->x3f)
        return 84;
    if (p1->i4 != p1->i4f && p1->x4 != p1->x4f)
        return 84;
    if (p1->i5 != p1->i5f && p1->x5 != p1->x5f)
        return 84;
    return 0;
}
