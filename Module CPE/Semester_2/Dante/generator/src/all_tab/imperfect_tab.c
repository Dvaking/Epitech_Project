/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** imperfect_tab
*/

#include <unistd.h>

#include "macro.h"
#include "struct.h"
#include "proto_generator.h"
#include "proto_lib_generator.h"

static int create_imperfect_on_top(tab_data_t *tab_data, int x, int *end)
{
    int wall = 0;
    if (tab_data == NULL)
        return KO;
    if (tab_data->tab[0][x] != '*')
        return OK;
    if (tab_data->tab[1][x] == 'X')
        wall += 1;
    if (tab_data->tab[0][x + 1] == 'X')
        wall += 1;
    if (tab_data->tab[0][x - 1] == 'X')
        wall += 1;
    if (wall >= 2){
        tab_data->tab[1][x] = 'X';
        tab_data->tab[0][x + 1] = 'X';
        tab_data->tab[0][x - 1] = 'X';
        *end = 1;
    }
    return OK;
}

static int create_imperfect_on_left(tab_data_t *tab_data, int y, int *end)
{
    int wall = 0;
    if (tab_data == NULL)
        return KO;
    if (tab_data->tab[y][0] != '*')
        return OK;
    if (tab_data->tab[y][1] == 'X')
        wall += 1;
    if (tab_data->tab[y + 1][0] == 'X')
        wall += 1;
    if (tab_data->tab[y - 1][0] == 'X')
        wall += 1;
    if (wall >= 2){
        tab_data->tab[y][1] = 'X';
        tab_data->tab[y + 1][0] = 'X';
        tab_data->tab[y - 1][0] = 'X';
        *end = 1;
    }
    return OK;
}

int imperfect_tab(tab_data_t *tab_data)
{
    int end = 0;
    if (tab_data == NULL)
        return KO;
    for (int y = 1; y != tab_data->y_max && end == 0; y += 1){
        if (create_imperfect_on_left(tab_data, y, &end) == KO)
            return KO;
    }
    for (int x = 1; x != tab_data->x_max && end == 0; x += 1){
        if (create_imperfect_on_top(tab_data, x, &end) == KO)
            return KO;
    }
    return OK;
}
