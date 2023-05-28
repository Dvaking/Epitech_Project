/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** modif_str
*/

#include <stdlib.h>
#include <unistd.h>

#include "proto_lib.h"
#include "proto_antman.h"

int selected_setence(list_t *selectioned, int *key)
{
    int count = my_strlen(selectioned->text);
    char *str_selectioned = create_str(selectioned, count);
    if (str_selectioned == NULL)
        return 1;
    selectioned->text = malloc(sizeof(char) * count + 5);
    if (selectioned->text == NULL)
        return 1;
    for (int i = 0; str_selectioned[i] != '\0' ; i += 1)
        selectioned->text[i] = str_selectioned[i];
    selectioned->text[count] = '~';
    selectioned->text[count + 1] = *key;
    selectioned->text[count + 2] = '\n';
    selectioned->text[count + 3] = '\0';
}

int modif_str(list_t *move, int *key)
{
    move->text = malloc(sizeof(char) * 4);
    if (move->text == NULL)
        return 1;
    move->text[0] = '~';
    move->text[1] = *key;
    move->text[2] = '\n';
    move->text[3] = '\0';

}
