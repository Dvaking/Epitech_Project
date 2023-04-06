/*
** EPITECH PROJECT, 2022
** swap_first_nodes
** File description:
** swap the two first nodes
*/

#include "linked_list.h"
#include <stdlib.h>

list_t *swap_first_nodes(list_t *list)
{
    list_t *e1 = list;
    list_t *e2 = list->next;
    list_t *e3 = list->next->next;

    e1 = e2;
    e1->next = e3;
    e1->previous = e2;
    e2->next = e1;
    e2->previous = NULL;

    return list;
}
