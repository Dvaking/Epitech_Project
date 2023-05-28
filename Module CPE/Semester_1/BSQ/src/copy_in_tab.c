/*
** EPITECH PROJECT, 2022
** copy_in_tab
** File description:
** copy a file in a tab
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "proto.h"
#include "struct.h"

void copy_in_tab(map_t *map, char **tab, char *buffer, char **av)
{
    struct stat s;
    int fd = open(av[1], O_RDONLY);
    int b = map -> nombre;
    stat(av[1], &s);
    read(fd, buffer, s.st_size);
    for (int lines = 0; lines < map -> lines; lines += 1){
        for (int cols = 0; cols < map -> columns; cols += 1) {
            tab[lines][cols] = buffer[b];
            b += 1;
        }
    }
    close(fd);
}
