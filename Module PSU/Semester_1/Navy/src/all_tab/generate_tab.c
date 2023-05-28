/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** generate_tab
*/

#include <unistd.h>
#include <stdlib.h>

char *number_binary_ter(int i)
{
    char *str = malloc(sizeof(char) * 4);
    if (str == NULL)
        return NULL;
    str[3] = '\0';
    for (int b = 0; b != 3; b += 1)
        str[b] = '0';
    switch (i){
        case 6:
            str[0] = '1';
            str[1] = '1';
            return str;
        case 7:
            str[0] = '1';
            str[1] = '1';
            str[2] = '1';
            return str;
    }
}

static char *number_binary_sub(int i)
{
    char *str = malloc(sizeof(char) * 4);
    if (str == NULL)
        return NULL;
    str[3] = '\0';
    for (int b = 0; b != 3; b += 1){
        str[b] = '0';
    }
    switch (i){
    case 4:
        str[0] = '1';
        return str;
    case 5:
        str[0] = '1';
        str[2] = '1';
        return str;
    }
}

static char *number_binary_zero(int i)
{
    char *str = malloc(sizeof(char) * 4);
    if (str == NULL)
        return NULL;
    str[3] = '\0';
    for (int b = 0; b != 3; b += 1)
        str[b] = '0';
    return str;
}

static char *number_binary(int i)
{
    char *str = malloc(sizeof(char) * 4);
    if (str == NULL)
        return NULL;
    str[3] = '\0';
    for (int b = 0; b != 3; b += 1)
        str[b] = '0';
    switch (i){
        case 1:
            str[2] = '1';
            return str;
        case 2:
            str[1] = '1';
            return str;
        case 3:
            str[1] = '1';
            str[2] = '1';
            return str;
    }
}

char **generate_tab(void)
{
    char **tab = malloc(sizeof(char *) * 9);
    tab[8] = NULL;
    for (int i = 0; i != 8; i += 1) {
        if (i == 0)
            tab[i] = number_binary_zero(i);
        if (i > 0 && i < 4)
            tab[i] = number_binary(i);
        if (i >= 4 && i < 6)
            tab[i] = number_binary_sub(i);
        if (i >= 6)
            tab[i] = number_binary_ter(i);
    }
    return tab;
}
