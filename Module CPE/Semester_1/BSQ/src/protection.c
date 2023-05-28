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

int protection_cinco(map_t *map, char *buffer, int *nbr)
{
    if ((map->columns - 1) != *nbr){
        free(buffer);
        free(map);
        exit(84);
    }
    *nbr = 0;
}

int protection_quad(map_t *map, int len, int fd, char *buffer)
{
    int count = 0;
    if (len == -1 || buffer == NULL){
        close(fd);
        free(buffer);
        free(map);
        exit(84);
    }
    for (int verif = 0; buffer[verif] != '\0'; verif += 1){
        if (buffer[verif] == '\n'){
            count += 1;
        }
    }
    if (count == 1) {
        close(fd);
        free(buffer);
        free(map);
        exit(84);
    }
}

int protection_ter(map_t *map, char *buffer, int count)
{
    int nbr = 0;
    for (int verif = count; buffer[verif] != '\0'; verif += 1){
        if (buffer[verif] != '\n') {
            nbr += 1;
        }
        if (buffer[verif] == '\n')
            protection_cinco(map, buffer, &nbr);
        if (buffer[verif] != '.' && buffer[verif] != 'o' && \
buffer[verif] != '\n'){
            free(buffer);
            free(map);
            exit(84);
        }
    }
    if (map->columns == 2 && map->lines == 1) {
        if (special_cas_sub(map, buffer, count) == 1) {
            return 1;
        }
    }
    return 0;
}

int protection_sub(square_t *square)
{
    if (square == NULL) {
        free(square);
        exit(84);
    }
}

int protection(map_t *map, int ac, int fd)
{
    if (ac < 2) {
        exit(84);
    }
    if (fd == -1) {
        close(fd);
        free(map);
        exit(84);
    }
    if (map == NULL) {
        close(fd);
        free(map);
        exit(84);
    }
}
