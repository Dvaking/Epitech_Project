/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** trouve le carré le pluus grand
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include "proto.h"
#include "struct.h"

static int getlines(map_t *map, char *buffer, int count)
{
    int lines = 0;
    for (int i = count; buffer[i] != '\0'; i += 1){
        if (buffer[i] == '\n') {
            lines += 1;
        }
    }
    return lines;
}

static int getcols(map_t *map, char *buffer, int count)
{
    int nomb = 0;
    for (int i = count; buffer[i] != '\n'; i += 1) {
        nomb += 1;
    }
    return nomb;
}

static void get_size(map_t *map, char *buffer)
{
    int count = 0;
    while (buffer[count] != '\n') {
        if (buffer[count] > '9' || buffer[count] < '0') {
            free(buffer);
            free(map);
            exit(84);
        }
        count += 1;
    }
    count += 1;
    map->nombre = count;
    map->lines = getlines(map, buffer, count);
    map->columns = getcols(map, buffer, count) + 1;
    if (protection_ter(map, buffer, count) == 1) {
        free(buffer);
        free(map);
        exit(0);
    }
}

static int bsq(map_t *map, struct stat s, char *buffer, char **av)
{
    char **tab;
    get_size(map, buffer);
    tab = malloc(sizeof(char *) * map -> lines);
    for (int lines = 0; lines < map -> lines; lines += 1){
        tab[lines] = malloc(sizeof(char) * map -> columns + 1);
        tab[lines][map -> columns] = '\0';
    }
    copy_in_tab(map, tab, buffer, av);
    redirection(map, tab);
    for (int lines = 0; lines < map->lines; lines += 1){
        free(tab[lines]);
    }
    free(tab);
    return 1;
}

int main(int argc, char **argv)
{
    map_t *map = malloc(sizeof(map_t));
    if (argv[1][0] > '0' && argv[1][0] <= '9'){
        generation_map(map, argc, argv);
    } else {
        int fd = open(argv[1], O_RDONLY);
        struct stat s;
        stat(argv[1], &s);
        protection(map, argc, fd);
        char *buffer = malloc(sizeof(char) * s.st_size + 1);
        buffer[s.st_size] = '\0';
        int len = read(fd, buffer, s.st_size);
        protection_quad(map, len, fd, buffer);
        close(fd);
        bsq(map, s, buffer, argv);
        free(buffer);
    }
    free(map);
    return 0;
}
