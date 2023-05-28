/*
** EPITECH PROJECT, 2022
** load_file_in_mem
** File description:
** load a file like a map and allocate it in the memory
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "proto.h"


static bool verify_line(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != 'X' && line[i] != '*')
            return false;
    }
    return true;
}

static bool verify_map(char **map, char *buffer)
{
    if (map == NULL || buffer == NULL)
        return NULL;
    if (buffer[strlen(buffer)] == '\n')
        return NULL;
    int i = 0;
    for (i = 0; map[i] != NULL; i++) {
        if (strlen(map[i]) != strlen(map[0]))
            return false;
        if (verify_line(map[i]) == false)
            return false;
    }
    if (map[0][0] != '*' || map[i - 1][strlen(map[0]) - 1] != '*')
        return false;
    return true;
}

char **load_file_in_mem(char const *filepath)
{
    struct stat s;
    int fd;
    if (filepath == NULL)
        return NULL;
    if ((fd = open(filepath, O_RDONLY)) == -1)
        return NULL;
    stat(filepath, &s);
    char *buffer = malloc(sizeof(char) * (s.st_size + 1));
    if (buffer == NULL)
        return NULL;
    buffer[s.st_size] = '\0';
    read(fd, buffer, s.st_size);
    if (buffer == NULL)
        return NULL;
    char **map = my_spliter(buffer, '\n');
    if (verify_map(map, buffer) == false)
        return NULL;
    close(fd);
    free(buffer);
    return map;
}
