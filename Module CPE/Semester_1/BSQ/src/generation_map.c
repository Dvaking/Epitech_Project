/*
** EPITECH PROJECT, 2022
** generation map
** File description:
** genere une map de taille donne
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "proto.h"
#include "struct.h"

static void reccup_nomb(map_t *map, char **av)
{
    int i = 0;
    long int j = 0;
    long int percent = 1;
    int taille = my_strlen(av[1]);
    for (int a = taille - 1;taille > 0; a -= 1){
        i = (av[1][a] - 48);
        j = i * percent;
        percent *= 10;
        taille -= 1;
    }
    if (j >= 2147483648) {
        free(map);
        exit(84);
    } else {
        map->lines = j;
    }
}

static void generation_map_ter(map_t *map, int y, char **av, char **tab)
{
    for (int x = 0; x < map->lines; x += 1){
        if (map->nombre >= my_strlen(av[2])) {
            map->nombre = 0;
        }
        tab[y][x] = av[2][map->nombre];
        map->nombre += 1;
    }
}

static void generation_map_sub(map_t *map, char **tab, char **av)
{
    for (int y = 0; y < map->lines; y += 1) {
        tab[y] = malloc(sizeof(char) * map->lines + 1);
        generation_map_ter(map, y, av, tab);
        tab[y][map->lines] = '\n';
    }
    map->columns = map->lines + 1;
    no_square_sub(map, tab);
}

void generation_map(map_t *map, int ac, char **av)
{
    protection_seis(map, ac, av);
    map->nombre = 0;
    map->lines = 0;
    reccup_nomb(map, av);
    if (map->lines == 1 && map->nombre == 1) {
        special_cas(map, av);
        return;
    } else {
        char **tab = malloc(sizeof(char *) * (map->lines + 1));
        for (int y = 0; y < map->lines; y += 1){
            tab[y] = malloc(sizeof(char) * map->lines + 1);
        }
        tab[map->lines] = NULL;
        generation_map_sub(map, tab, av);
        for (int lines = 0; lines < map->lines; lines += 1){
            free(tab[lines]);
        }
        free(tab);
    }
}
