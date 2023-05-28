/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** display_tab
*/

#include <unistd.h>

#include "macro.h"
#include "struct.h"
#include "proto_generator.h"
#include "proto_lib_generator.h"

static int condition_breakline(tab_data_t *tab_data, int y)
{
    if (tab_data == NULL)
        return KO;
    if ((tab_data->y_max - y) != 1){
        if (write(1, "\n", 1) == -1)
            return KO;
    }
    return OK;
}

int display_tab(tab_data_t *tab_data)
{
    int len_str = 0;
    for (int y = 0; y != tab_data->y_max; y += 1){
        len_str = my_strlen(tab_data->tab[y]);
        if (len_str == KO)
            return KO;
        if (write(1, tab_data->tab[y], len_str) == -1)
            return KO;
        if (condition_breakline(tab_data, y) != OK)
            return KO;
    }
    return 0;
}
