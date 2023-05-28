/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** check_argc_argv
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "macro.h"
#include "proto_lib_generator.h"

static int write_value(char *str, int len_str, int i_max)
{
    if (str == NULL)
        return KO;
    for (int i = 0; i != i_max; i += 1){
        if (write(1, str, len_str) == -1)
            return KO;
    }
}

static int one_line_value(int x, int y)
{
    if (x == 1){
        if (write_value("*\n", 2, y) == KO)
            return KO;
        exit(0);
    }
    if (y == 1){
        if (write_value("*", 1, x) == KO)
            return KO;
        if (write(1, "\n", 1) == KO)
            return KO;
        exit(0);
    }
}

static int check_argv(char const *const *av, int y)
{
    int y2 = char_to_int(av[2]);
    int x = char_to_int(av[1]);
    for (int x = 0; av[y][x] != '\0'; x += 1){
        if (av[y][x] < '0' || av[y][x] > '9')
            return KO;
    }
    if (x == 1 && y2 == 1){
        if (write(1, "*\n", 2) == KO)
            return KO;
        exit(0);
    }
    if (x == 0 || y2 == 0)
        exit(0);
    if (x == 1 || y2 == 1)
        one_line_value(x ,y2);
    return OK;
}

int check_argc_argv(int argc, char const *const *argv)
{
    if (argv == NULL)
        return KO;
    if (argc < 3 || argc > 4)
        return KO;
    for (int y = 1; y != 2; y += 1) {
        if (check_argv(argv, y) != 0)
            return KO;
    }
    return OK;
}
