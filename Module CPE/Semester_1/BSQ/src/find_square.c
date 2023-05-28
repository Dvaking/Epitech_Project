/*
** EPITECH PROJECT, 2022
** find_square
** File description:
** find square in my 2D tab
*/

#include <stdlib.h>

#include "proto.h"
#include "struct.h"


static void find_square_ter(map_t *map, square_t *square, char **tab)
{
    if (tab[square->rows][square->cols] == '.') {
        while (bigger_square(map, square, tab) == 0) {
            square->size += 1;
            square->max_x = square->cols;
            square->max_y = square->rows;
        }
    }
    square->cols += 1;
}

static void find_square_sub(map_t *map, square_t *square, char **tab)
{
    while (square->rows < map->lines) {;
        while (square->cols <= map->columns){
            find_square_ter(map, square, tab);
        }
        square->rows += 1;
        square->cols = 0;
    }
    display_tab_with_x(map, square, tab);
}

void find_square(map_t *map, char **tab)
{
    square_t *square = malloc(sizeof(square_t));
    protection_sub(square);
    square->cols = 0;
    square->rows = 0;
    square->size = 0;
    square->max_x = 0;
    square->max_y = 0;
    find_square_sub(map, square, tab);
    free(square);
}
