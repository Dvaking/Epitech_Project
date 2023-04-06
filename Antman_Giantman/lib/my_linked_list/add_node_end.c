/*
** EPITECH PROJECT, 2022
** add node end
** File description:
** add a node in the end of a linked list
*/

#include <stdlib.h>

#include "my.h"

list_t *add_node_end(list_t *list, char *lines)
{
    list_t *node = list;
    list_t *new_node = create_list(lines);
    if (new_node == NULL)
        return NULL;
    if (list == NULL) {
        list = create_list(lines);
        return list;
    }
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = new_node;
    new_node->next = NULL;
    new_node->previous = node;
    return list;
}
