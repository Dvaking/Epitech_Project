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

char *create_str(list_t *list, int lenght)
{
    int count = 0;
    int start = 0;
    char *str;
    if (lenght < 1) {
        count = my_strlen(list->text);
        str = malloc(sizeof(char) * count + 1);
        str[count] = '\0';
    } else {
        str = malloc(sizeof(char) * lenght + 2);
        str[0] = '~';
        str[lenght + 1] = '\0';
        start = 1;
    }
    if (str == NULL)
        return NULL;
    for (int i = 0 + start; list->text[i - start] != '\0'; i += 1)
        str[i] = list->text[i - start];
    return str;
}
