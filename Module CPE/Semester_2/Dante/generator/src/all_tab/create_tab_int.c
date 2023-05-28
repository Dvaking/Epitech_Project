/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** create_tab_int
*/

#include <unistd.h>

#include "macro.h"
#include "struct.h"
#include "proto_generator.h"
#include "proto_lib_generator.h"

int **create_tab_int(tab_data_t *tab_data)
{
    int **tab = int_tab_generator(4, 2);
    if (tab == NULL)
        return NULL;
    tab[0][0] = -1;
    tab[0][1] = 0;
    tab[1][0] = 1;
    tab[1][1] = 0;
    tab[2][0] = 0;
    tab[2][1] = -1;
    tab[3][0] = 0;
    tab[3][1] = 1;
    return tab;
}
