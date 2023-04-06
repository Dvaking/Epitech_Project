/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** take_data
*/

#include "macro.h"
#include "struct.h"
#include "proto_lib_generator.h"

int take_data(tab_data_t *tab_data, char const *const *av)
{
    tab_data->x_max = char_to_int(av[1]);
    tab_data->y_max = char_to_int(av[2]);
    if (tab_data->y_max > 1500 && tab_data->x_max > 1500)
        return KO;
    if (tab_data->x_max == -1 || tab_data->y_max == -1)
        return KO;
    return OK;
}
