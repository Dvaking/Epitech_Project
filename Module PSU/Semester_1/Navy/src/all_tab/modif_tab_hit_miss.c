/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** check_tab_signal
*/

#include "struct.h"
#include "proto_lib.h"

extern variable_global_t variable_global;

int check_player_tab(char **tab, char *attack)
{
    int x = 0;
    int y = 0;
    for (int i = 0; tab[0][i] != attack[0]; i += 1)
        x += 1;
    for (int i = 0; tab[i][0] != attack[1]; i += 1)
        y += 1;
    if (tab[y][x] != '.' && tab[y][x] != ' ' && tab[y][x] != 'x'){
        return 1;
    } else if (tab[y][x] == '.' && tab[y][x] != ' '){
        return 0;
    }
}

void modif_tab_hit_miss(char **tab_neutral, char *entry, int i)
{
    int x = 0;
    int y = 0;
    for (int i = 0; tab_neutral[0][i] != entry[0]; i += 1)
        x += 1;
    for (int i = 0; tab_neutral[i][0] != entry[1]; i += 1)
        y += 1;
    if (i == 1)
        tab_neutral[y][x] = 'x';
    if (i == 0 && tab_neutral[y][x] != 'x')
        tab_neutral[y][x] = 'o';
}
