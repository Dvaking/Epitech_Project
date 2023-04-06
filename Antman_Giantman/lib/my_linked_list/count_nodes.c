/*
** EPITECH PROJECT, 2022
** count_nodes
** File description:
** count the number of nodes in a linked list
*/

#include <stdlib.h>
#include "linked_list.h"

int count_nodes(list_t *list)
{
    list_t *node = list;
    int count = 0;
    while (node != NULL) {
        count += 1;
        node = node->next;
    }
    return count;
}
