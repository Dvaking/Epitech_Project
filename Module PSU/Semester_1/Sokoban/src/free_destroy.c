/*
** EPITECH PROJECT, 2022
** free destroys
** File description:
** free_destroy
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "proto.h"
#include "struct.h"

void free_map(map_size_t *map_size, char **map, char **map_copy)
{
    for (int lines = 0; lines < map_size->lines; lines += 1){
        free(map[lines]);
        free(map_copy[lines]);
    }
    free(map);
    free(map_copy);
}

void free_struct_buff_fd(map_size_t *map_size, charact_box_t *charact_box, \
char *buffer, int fd)
{
    free(charact_box->hole);
    free(charact_box);
    free(map_size);
    free(buffer);
    close(fd);
}
