/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** error_handing
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int error_file_buffer(struct stat s, int fd, char *buffer, char **av)
{
    if (fd == -1) {
        close(fd);
        free(buffer);
        return 84;
    }
    if (buffer == NULL){
        close(fd);
        free(buffer);
        return 84;
    }
    if (stat(av[1], &s) == -1) {
        close(fd);
        free(buffer);
        return 84;
    }
    return 0;
}
