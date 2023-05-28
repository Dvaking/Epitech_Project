/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** signal_to_char
*/

#include <unistd.h>
#include <stdlib.h>

#include "proto_lib.h"

static char *translation(int letter, int number, char **binary_tab)
{
    char *str = malloc(sizeof(char) * 3);
    str[2] = '\0';
    str[0] = (letter + 'A');
    str[1] = (number + '1');
    return str;
}

char *signal_to_char(char *reception, char **binary_tab)
{
    char *str;
    int b = 4;
    int letter = 0;
    int number = 0;
    for (int i = 0; i != 3; i += 1){
        letter += ((reception[i] - '0') * b);
        b /= 2;
    }
    b = 4;
    for (int i = 3; i != 6; i += 1){
        number += ((reception[i] - '0') * b);
        b /= 2;
    }
    if ((str = translation(letter, number, binary_tab)) == NULL)
        return NULL;
    return str;
}
