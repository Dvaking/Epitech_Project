/*
** EPITECH PROJECT, 2023
** free_node.c
** File description:
** free a node
*/

#include <stdlib.h>
#include "open_and_closed_lists.h"

box_list_s *free_node(box_list_s *list)
{
    box_list_s *node = list;

    while (node != NULL) {
        node = node->next;
        free(list);
        list = node;
    }
    return list;
}
