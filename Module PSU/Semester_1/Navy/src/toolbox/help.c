/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** help
*/

#include "proto_lib.h"

void print_point(int a, char *str, int x)
{
    if (a == 0)
        str[x] = '.';
}

int help(char **av)
{
    if (av[1][1] == 'h' && av[1][2] == '\0'){
        my_printf("USAGE\n    ./navy [first_player_pid] navy_positions\n\
DESCRIPTION\n    first_player_pid: only for the 2nd player. pid of the first\
player.\n    navy_positions: file representing the positions of the\
ships.\n");
    } else {
        my_printf("Flag invalid\n");
        return 84;
    }
    return 0;
}
