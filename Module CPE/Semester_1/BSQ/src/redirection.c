/*
** EPITECH PROJECT, 2022
** redirection
** File description:
** redirect to my fonction
*/

#include "proto.h"
#include "struct.h"

static int find_o(map_t *map, char **tab, int lines)
{
    for (int cols = 0; cols < map -> columns; cols += 1){
        if (tab[lines][cols] == 'o'){
            find_square(map, tab);
            return 1;
        }
    }
}

void redirection(map_t *map, char **tab)
{
    for (int lines = 0; lines < map -> lines; lines += 1){
        if (find_o(map, tab, lines) == 1) {
            return;
        }
    }
    no_square(map, tab);
}
