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

static int shuffle_value(int **tab)
{
    for (int i = 0; i != 4; i += 1) {
        int random = rand() % 4;
        int *temp = tab[i];
        tab[i] = tab[random];
        tab[random] = temp;
    }
    return 0;
}

static int create_maze(tab_data_t *tab_data, int **y_x, move_s_t move)
{
    shuffle_value(y_x);
    for (int i = 0; i != 4; i += 1){
        move_s_t move_next = {.x = (move.x + y_x[i][1]),
        .y = (move.y + y_x[i][0])};
        move_s_t move_next_next = {.x = (move.x + (y_x[i][1] + y_x[i][1])),
        .y = (move.y + (y_x[i][0] + y_x[i][0]))};
        if (move_condition(tab_data, move, y_x, i) == OK){
            tab_data->tab[move_next.y][move_next.x] = '*';
            tab_data->tab[move_next_next.y][move_next_next.x] = '*';
            move.x = move_next_next.x;
            move.y = move_next_next.y;
        }
    }
    return OK;
}

int create_labyrinth(tab_data_t *tab_data, int **tab_y_x)
{
    shuffle_value(tab_y_x);
    move_s_t move = {.x = 0, .y = 0};
    create_maze(tab_data, tab_y_x, move);
    for (move.y = 0; move.y < tab_data->y_max; move.y += 2){
        for (move.x = 0; move.x < tab_data->x_max; move.x += 2){
            create_maze(tab_data, tab_y_x, move);
        }
    }
    return OK;
}
