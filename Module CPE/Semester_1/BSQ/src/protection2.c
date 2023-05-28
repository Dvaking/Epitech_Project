/*
** EPITECH PROJECT, 2022
** protection
** File description:
** find error
*/

#include <dirent.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "proto.h"
#include "struct.h"

int protection_seis(map_t *map, int ac, char **av)
{
    if (ac < 3) {
        free(map);
        exit(84);
    }
    if (my_strlen(av[2]) == 0) {
        free(map);
        exit(84);
    }
    if (map == NULL) {
        free(map);
        exit(84);
    }
    for (int i = 0; av[2][i] != '\0'; i += 1){
        if (av[2][i] != '.' && av[2][i] != 'o'){
            free(map);
            exit(84);
        }
    }
}

int protection_seite(map_t *map, int max_x, int max_y)
{
    if (max_y > map->lines){
            return 1;
    }
    if (max_x > map->columns){
        return 1;
    }
}
