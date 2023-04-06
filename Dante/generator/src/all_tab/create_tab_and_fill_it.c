/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** all_tab
*/

#include <unistd.h>

#include "proto_generator.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib_generator.h"

int create_tab_and_fill_it(tab_data_t *tab_data, char const *const *av)
{
    int wall_or_cells = 1;
    int nbr = 0;
    if (take_data(tab_data, av) != OK)
        return KO;
    tab_data->tab = char_tab_generator(tab_data->y_max, tab_data->x_max);
    if (tab_data->tab == NULL)
        return KO;
    for (int y = 0; y != tab_data->y_max; y += 1){
        for (int x = 0; x != tab_data->x_max; x += 1)
            tab_data->tab[y][x] = 'X';
    }
    tab_data->tab[0][0] = '*';
    tab_data->tab[tab_data->y_max - 1][tab_data->x_max - 1] = '*';
    tab_data->tab[tab_data->y_max - 1][tab_data->x_max - 2] = '*';
    return OK;
}
