/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** free
*/

#include <stdlib.h>
#include <unistd.h>

#include "macro.h"
#include "struct.h"
#include "proto_generator.h"

int free_all(tab_data_t *tab_data, int **tab)
{
    if (free_struct(tab_data) != OK)
        return KO;
    for (int i = 0; i != 4; i += 1)
        free(tab[i]);
    free(tab);
}

int free_struct(tab_data_t *tab_data)
{
    if (tab_data == NULL)
        return KO;
    for (int i = 0; i != tab_data->y_max; i += 1){
        free(tab_data->tab[i]);
    }
    free(tab_data->tab);
    free(tab_data);
}
