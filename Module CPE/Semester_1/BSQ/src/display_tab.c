/*
** EPITECH PROJECT, 2022
** display_tab
** File description:
** display my 2D tab
*/
#include <unistd.h>
#include <stdio.h>

#include "proto.h"
#include "struct.h"

void display_tab(map_t *map, char **tab)
{
    int taille = my_strlen(tab[0]);
    for (int lines = 0; lines < map -> lines; lines += 1){
        write(1, tab[lines], taille);
    }
}

void display_tab_with_x(map_t *map, square_t *square, char **tab)
{
    int max_y = (square->max_y + square->size);
    int max_x = (square->max_x + square->size);
    if (square->size == 0 && max_y == 0 && max_x == 0) {
        display_tab(map, tab);
        return;
    }
    for (int y = square->max_y; y < max_y; y += 1) {
        for (int x = square->max_x; x < max_x; x += 1) {
            tab[y][x] = 'x';
        }
    }
    display_tab(map, tab);
}
