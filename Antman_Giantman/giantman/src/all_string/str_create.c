/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** create_str
*/

#include <unistd.h>
#include <stdlib.h>

#include "linked_list.h"
#include "proto_lib.h"

char *str_create(list_t *list)
{
    int count = my_strlen(list->text);
    int start = 1;
    char *str = malloc(sizeof(char) * count);
    if (str == NULL)
        return NULL;

    for (int i = 0; list->text[i + start] != '~'; i += 1)
        str[i] = list->text[i + start];
    str[count - 4] = '\0';
    count = my_strlen(str);
    list->text = malloc(sizeof(char) * count + 2);
    if (list->text == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i += 1)
        list->text[i] = str[i];
    list->text[count] = '\n';
    return str;
}
