/*
** EPITECH PROJECT, 2022
** no_square
** File description:
** if there is no square
*/

#include "proto.h"
#include "struct.h"

void no_square(map_t *map, char **tab)
{
    map->columns -= 1;
    if (map->lines == 1) {
        for (int cols = 0; cols < map->lines; cols += 1) {
            tab[0][cols] = 'x';
            display_tab(map, tab);
            return;
        }
    }
    for (int lines = 0; lines < map -> columns && lines < map->lines; \
lines += 1){
        for (int cols = 0; cols < map -> columns && cols < map->lines; \
cols += 1) {
            tab[lines][cols] = 'x';
        }
    }
    display_tab(map, tab);
}

static int find_o(map_t *map, char **tab, int lines)
{
    for (int cols = 0; cols < map -> columns; cols += 1){
        if (tab[lines][cols] == 'o'){
            find_square(map, tab);
            return 1;
        }
    }
}

void no_square_sub(map_t *map, char **tab)
{
    for (int lines = 0; lines < map -> lines; lines += 1){
        if (find_o(map, tab, lines) == 1) {
            return;
        }
    }
    for (int lines = 0; lines < map -> columns - 1; lines += 1){
        for (int cols = 0; tab[lines][cols] == '.'; cols += 1) {
            tab[lines][cols] = 'x';
        }
    }
    display_tab(map, tab);
}
