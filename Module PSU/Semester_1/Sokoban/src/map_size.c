/*
** EPITECH PROJECT, 2022
** map size
** File description:
** len map
*/

#include "proto.h"
#include "struct.h"

static void getlines(map_size_t *map_size, char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i += 1){
        if (buffer[i] == '\n') {
            map_size->lines += 1;
        }
    }
}

static void getcols(map_size_t *map_size, char *buffer)
{
    int nomb = 0;
    int b = 0;
    int y = 0;
    while (buffer[b] != '\0'){
        while (buffer[b] != '\n') {
            nomb += 1;
            b += 1;
        }
        if (nomb > map_size->columns){
            map_size->columns = nomb;
        }
        nomb = 0;
        b += 1;
    }
}

void get_size(map_size_t *map_size, char *buffer)
{
    map_size->columns = 0;
    map_size->lines = 0;
    getlines(map_size, buffer);
    getcols(map_size, buffer);
    map_size->columns += 1;
}
