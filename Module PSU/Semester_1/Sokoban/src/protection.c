/*
** EPITECH PROJECT, 2022
** protection
** File description:
** protection
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "proto.h"
#include "struct.h"

int protection(int fd, char *buffer, map_size_t *map_size, \
charact_box_t *charact_box)
{
    int return_value = 0;
    if (fd == -1) {
        free_struct_buff_fd(map_size, charact_box, buffer, fd);
        return_value = 84;
    }
    if (map_size == NULL) {
        free_struct_buff_fd(map_size, charact_box, buffer, fd);
        return_value = 84;
    }
    if (charact_box == NULL) {
        free_struct_buff_fd(map_size, charact_box, buffer, fd);
        return_value = 84;
    }
    if (buffer == NULL) {
        free_struct_buff_fd(map_size, charact_box, buffer, fd);
        return_value = 84;
    }
    return return_value;
}
