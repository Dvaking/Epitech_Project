/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** generator
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "macro.h"
#include "proto_generator.h"
#include "proto_lib_generator.h"
#include "struct.h"

int generator(int ac, char const *const *av)
{
    srand(time(NULL));
    int **tab = NULL;
    tab_data_t *tab_data = malloc(sizeof(tab_data_t));
    if (av == NULL || tab_data == NULL)
        return 84;
    if (create_tab_and_fill_it(tab_data, av) != OK)
        return 84;
    if ((tab = create_tab_int(tab_data)) == NULL)
        return 84;
    if (create_maze(tab_data, tab, 0, 0) != OK)
        return 84;
    if (perfect_or_not(tab_data, ac, av) != OK)
        return 84;
    if (display_tab(tab_data) != OK)
        return 84;
    if (free_all(tab_data, tab) != OK)
        return 84;
    return 0;
}
