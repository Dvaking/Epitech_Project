/*
** EPITECH PROJECT, 2022
** bigger square
** File description:
** find if i find a bigger square
*/

#include <stdlib.h>

#include "proto.h"
#include "struct.h"

static int bigger_square_sub(square_t *square, char **tab, int y, int max_x)
{
    for (int x = square->cols; x <= max_x; x += 1) {
        if (tab[y][x] != '.'){
            return 1;
        }
    }
    return 0;
}

int bigger_square(map_t *map, square_t *square, char **tab)
{
    int max_y = (square->rows + square->size);
    int max_x = (square->cols + square->size);
    if (protection_seite(map, max_x, max_y) == 1)
        return 1;
    for (int y = square->rows; y <= max_y ; y += 1) {
        if (tab[y] == NULL){
            return 1;
        }
        if (bigger_square_sub(square, tab, y, max_x) == 1){
            return 1;
        }
    }
    return 0;
}
