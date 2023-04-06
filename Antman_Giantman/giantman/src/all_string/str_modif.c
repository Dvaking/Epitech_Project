/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** modif_str
*/

#include <stdlib.h>
#include <unistd.h>

#include "proto_lib.h"
#include "proto_giantman.h"

int str_modif(list_t *move, char *str)
{
    int count = my_strlen(str);
    move->text = malloc(sizeof(char) * count + 2);
    move->text[count] = '\n';
    move->text[count + 1] = '\0';
    if (move->text == NULL)
        return 1;
    for (int i = 0; str[i] != '\0'; i += 1) {
        move->text[i] = str[i];
    }
}
