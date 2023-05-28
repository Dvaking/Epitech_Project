/*
** EPITECH PROJECT, 2022
** load_file_in_mem
** File description:
** load a file like a map and allocate it in the memory
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

int my_strlen(char const *str);

static bool open_file(int fd)
{
    if (fd == -1) {
        write(2, "ERROR : Script not found.\n", 27);
        return false;
    }
    return true;
}

static int check_str(char *buffer)
{
    int count = 0;
    for (int i = 0; buffer[i] != '\0'; i += 1){
        if (buffer[i] >= '!' && buffer[i] <= '~')
            count += 1;
    }
    if (count != 0)
        return 1;
    return 0;
}

char *load_file_in_mem(char *filepath)
{
    struct stat s;
    int fd = open(filepath, O_RDONLY);
    if (open_file(fd) == false)
        return NULL;
    stat(filepath, &s);
    int size = s.st_size;
    char *buffer = malloc(sizeof(char) * (size + 1));
    buffer[size] = '\0';
    if (read(fd, buffer, size) == -1) {
        free(buffer);
        return NULL;
    }
    if (check_str(buffer) == 1)
        return NULL;
    if (buffer == NULL)
        return NULL;
    close(fd);
    return buffer;
}
