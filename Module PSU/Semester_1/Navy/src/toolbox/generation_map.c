/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** generation_map
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "proto.h"
#include "struct.h"
#include "proto_lib.h"


static int *find_boat(t_player *p1, char *str, int i, int x)
{
    int a = 0;
    if ((x >= p1->x2 && x <= p1->x2f) && (i >= p1->i2 && i <= p1->i2f)){
        str[x] = '2';
        a = 1;
    }
    if (a == 0 && (x >= p1->x3 && x <= p1->x3f) &&
    (i >= p1->i3 && i <= p1->i3f)){
        str[x] = '3';
        a = 1;
    }
    if (a == 0 && (x >= p1->x4 && x <= p1->x4f) &&
    (i >= p1->i4 && i <= p1->i4f)){
        str[x] = '4';
        a = 1;
    }
    if (a == 0 && (x >= p1->x5 && x <= p1->x5f) &&
    (i >= p1->i5 && i <= p1->i5f)){
        str[x] = '5';
    }
}

static char *line_two_to_end_generation(int i, t_player *p1, int a)
{
    int count = i - 3;
    char *str = malloc(sizeof(char) * 18);
    str[17] = '\0';
    if (str == NULL)
        return NULL;
    str[0] = ('2' + count);
    str[1] = '|';
    for (int x = 2; x != 17; x += 1){
        if (x % 2 == 0)
            str[x] = '.';
        if (x % 2 != 0)
            str[x] = ' ';
        if (x % 2 != 1 && a == 1)
            find_boat(p1, str, i, x);
    }
    return str;
}

static char *first_line_generaction(void)
{
    int count = 0;
    char *str = malloc(sizeof(char) * 18);
    if (str == NULL)
        return NULL;
    str[17] = '\0';
    str[0] = ' ';
    str[1] = '|';
    for (int x = 2; x != 16; x += 2) {
        str[x] = ('A' + count);
        str[x + 1] = ' ';
        count += 1;
    }
    str[16] = 'H';
    return str;
}

static char *generation_all(int i, t_player *p1, int a)
{
    if (i == 0) {
        char *str = first_line_generaction();
        return str;
    }
    if (i == 1) {
        char *str = malloc(sizeof(char) * 18);
        str[17] = '\0';
        if (str == NULL)
            return NULL;
        str[0] = '-';
        str[1] = '+';
        for (int x = 2; x != 17; x += 1)
            str[x] = '-';
        return str;
    }
    if (i > 1) {
        char *str = line_two_to_end_generation(i, p1, a);
        return str;
    }
}

char **generation_map(t_player *p1, int a)
{
    char **tab = malloc(sizeof(char *) * 11);
    tab[10] = NULL;
    for (int i = 0; i != 10; i += 1){
        tab[i] = generation_all(i, p1, a);
        if (tab[i] == NULL)
            return NULL;
    }
    return tab;
}
