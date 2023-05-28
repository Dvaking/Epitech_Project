/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** move_condition
*/

#include "macro.h"
#include "struct.h"

int move_condition(tab_data_t *tab_data, move_s_t move, int **tab, int i)
{
    int y2 = tab[i][0] + tab[i][0];
    int x2 = tab[i][1] + tab[i][1];
    int y = tab[i][0];
    int x = tab[i][1];
    if (((move.x + x2) > (tab_data->x_max - 1) || (move.x + x2) < 0)
    || (((move.y + y2) > (tab_data->y_max - 1) || (move.y + y2) < 0)))
        return KO;
    if (tab_data->tab[move.y + y][move.x + x] == 'X' &&
    tab_data->tab[move.y + y2][move.x + x2] == 'X'){
        return OK;
    }
    return KO;
}
