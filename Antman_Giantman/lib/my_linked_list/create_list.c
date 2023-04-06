/*
** EPITECH PROJECT, 2022
** create_list
** File description:
** create a linked list
*/

#include "linked_list.h"
#include <stdlib.h>
#include <math.h>

list_t *create_list(char *lines)
{
    list_t *list = malloc(sizeof(list_t));
    if (list == NULL)
        return NULL;
    list->text = lines;
    list->next = NULL;
    list->previous = NULL;
    return list;
}
