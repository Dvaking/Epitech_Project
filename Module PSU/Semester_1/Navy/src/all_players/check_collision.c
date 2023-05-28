/*
** EPITECH PROJECT, 2023
** check collision
** File description:
** check collision
*/
#include "proto.h"
#include "struct.h"
#include "proto_lib.h"
#include <stddef.h>

int check_point(char **tab, int i, int count)
{
    for (int x = 0; tab[i][x] != '\0'; x += 1){
        if (tab[i][x] == '.'){
            count += 1;
        }
    }
    return count;
}

int check_collision(char **tab)
{
    int count = 0;
    for (int i = 0; tab[i] != NULL; i += 1){
        count = check_point(tab, i, count);
    }
    return count;
}
