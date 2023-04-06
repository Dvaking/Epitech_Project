/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** add_way
*/

#include <unistd.h>
#include <stdlib.h>


#include "macro.h"
#include "struct.h"
#include "proto_generator.h"
#include "proto_lib_generator.h"

static int add_way_condition(tab_data_t *tab_data, int y, int x)
{
    int way = 0;
    if (tab_data->tab[y][x] == '*')
        return 3;
    if (tab_data->tab[y][x + 1] == '*')
        way += 1;
    if (tab_data->tab[y][x - 1] == '*')
        way += 1;
    if (tab_data->tab[y + 1][x] == '*')
        way += 1;
    if (tab_data->tab[y - 1][x] == '*')
        way += 1;
    if (way == 2){
        tab_data->tab[y][x] = '*';
        tab_data->rm_wall -= 1;
        return OK;
    }
    return KO;
}

int add_way(tab_data_t *tab_data, int wall)
{
    int x = rand() % (tab_data->x_max - 2);
    int y = rand() % (tab_data->y_max - 2);
    if (tab_data->rm_wall == 0)
        return OK;
    if (add_way_condition(tab_data, y, x) == OK){
        return OK;
    } else {
        add_way(tab_data, wall);
    }
    return OK;
}
