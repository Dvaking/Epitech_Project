/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-marc.mendia
** File description:
** check_file
*/

#include <stdio.h>
#include <stdlib.h>

#include "proto_lib.h"
#include "proto.h"
#include "struct.h"

static int check_open_file(FILE *file)
{
    if (file == NULL){
        my_printf("%s\n", "Error : wrong file");
        return 84;
    }
}

static int check_file_sub(char *line, int i)
{
    if (line[0] != i + '0'){
        my_printf("%s\n", "Error : boat's first number isn't valid");
        return 84;
    }
    if ((line[2] < 'A' || line[2] > 'H') || (line[5] < 'A' || line[5] > 'H')
    || (line[3] < '1' || line[3] > '8') || (line[6] < '1' || line[6] > '8')
    || (line[1] != ':' || line[4] != ':')){
        my_printf("%s\n", "Error : boat's coordinates aren't valid");
        return 84;
    }
    if ((line[5] - line[2]) + (line [6] - line[3]) != i - 1){
        my_printf("%s\n", "Error : boat's length isn't valid");
        return 84;
    }
}

int check_file(char **av, int n)
{
    int i = 2;
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    file = fopen(av[n], "r");
    if (check_open_file(file) == 84)
        return 84;
    while ((nread = getline(&line, &len, file)) != -1) {
        if (my_strlen(line) != 8 && my_strlen(line) != 7){
            my_printf("%s\n", "Error : file isn't valid");
            return 84;
        }
        if (check_file_sub(line, i) == 84)
            return 84;
        i += 1;
    }
    free(line);
    fclose(file);
    return 0;
}
