/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** display_all
*/

#include <unistd.h>
#include <stdbool.h>

#include "proto_lib.h"
#include "proto.h"
#include "struct.h"

void display_all(char **tab, char **tab_neutral)
{
        write(1, "\nmy positions:\n", 15);
        for (int i = 0; tab[i] != NULL; i += 1){
            write(1, tab[i], my_strlen(tab[i]));
            write(1, "\n", 1);
        }
        write(1, "\nenemy's positions:\n", 20);
        for (int i = 0; tab_neutral[i] != NULL; i += 1){
            write(1, tab_neutral[i], my_strlen(tab_neutral[i]));
            write(1, "\n", 1);
        }
}
