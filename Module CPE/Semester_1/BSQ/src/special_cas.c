/*
** EPITECH PROJECT, 2022
** soecial cas
** File description:
** gere cas special
*/

#include "proto.h"
#include "struct.h"

void special_cas(map_t *map, char **av)
{
    if (av[2][0] == '.'){
        my_putchar('x');
        return;
    }
    if (av[2][0] == 'o'){
        my_putchar('o');
        return;
    }
}

int special_cas_sub(map_t *map, char *buffer, int count)
{
    if (buffer[count] == '.'){
        my_putstr("x\n");
        return 1;
    }
    if (buffer[count] == 'o'){
        my_putstr("o\n");
        return 1;
    }
}
