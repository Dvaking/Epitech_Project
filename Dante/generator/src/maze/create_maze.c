/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** create_maze
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "macro.h"
#include "struct.h"
#include "proto_generator.h"
#include "proto_lib_generator.h"

static int value_move(int **tab)
{
    for (int i = 0; i != 4; i += 1) {
        int random = rand() % 4;
        int *temp = tab[i];
        tab[i] = tab[random];
        tab[random] = temp;
    }
    return 0;
}

int create_maze(tab_data_t *tab_data, int **tab, int y, int x)
{
    int y_x[2] = {y, x};
    value_move(tab);
    for (int i = 0; i != 4; i += 1){
        if (move_condition(tab_data, tab, y_x, i) == OK){
            create_maze(tab_data, tab, (y_x[0] + (tab[i][0] + tab[i][0])),
            (y_x[1] + (tab[i][1] + tab[i][1])));
        }
    }
    return OK;
}
