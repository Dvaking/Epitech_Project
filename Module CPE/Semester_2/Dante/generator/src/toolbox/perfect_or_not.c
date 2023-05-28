/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** perfect_or_not
*/

#include <unistd.h>

#include "macro.h"
#include "struct.h"
#include "proto_generator.h"
#include "proto_lib_generator.h"

static void how_many_wall_sub(tab_data_t *tab_data, int y, int wall)
{
    for (int x = 0; x != tab_data->y_max; x += 1){
        if (tab_data->tab[y][x] == 'X')
            wall += 1;
    }
}

static int how_many_wall(tab_data_t *tab_data)
{
    long long unsigned int wall = 0;
    for (int i = 0; i != tab_data->y_max; i += 1){
            how_many_wall_sub(tab_data, i, wall);
    }
}

int perfect_or_not(tab_data_t *tab_data, int ac, char const *const *av)
{
    int len_str = 0;
    long long unsigned int wall = how_many_wall(tab_data);
    if (av == NULL || tab_data == NULL)
        return KO;
    if (wall >= 10){
        tab_data->rm_wall = (wall * 0.1);
        add_way(tab_data, wall);
    }
    if (ac == 4){
        if ((len_str = my_strlen(av[3])) == KO)
            return KO;
        if (my_strncmp("perfect", av[3], len_str) == OK){
            return OK;
        }
    }
    imperfect_tab(tab_data);
    return OK;
}
