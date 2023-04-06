/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** move_condition
*/

#include "macro.h"
#include "struct.h"

int move_condition(tab_data_t *tab_data, int **tab, int *y_x, int i)
{
    int y2 = tab[i][0] + tab[i][0];
    int x2 = tab[i][1] + tab[i][1];
    int y = tab[i][0];
    int x = tab[i][1];
    if (((y_x[1] + x2) > (tab_data->x_max - 1) || (y_x[1] + x2) < 0)
    || (((y_x[0] + y2) > (tab_data->y_max - 1) || (y_x[0] + y2) < 0)))
        return KO;
    if (tab_data->tab[y_x[0] + y][y_x[1] + x] == 'X' &&
    tab_data->tab[y_x[0] + y2][y_x[1] + x2] == 'X'){
        tab_data->tab[y_x[0] + y][y_x[1] + x] = '*';
        tab_data->tab[y_x[0] + y2][y_x[1] + x2] = '*';
        return OK;
    }
    return KO;
}
