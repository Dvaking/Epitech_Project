/*
** EPITECH PROJECT, 2022
** count_nodes
** File description:
** count the number of nodes in a linked list
*/

#include <stdlib.h>
#include "open_and_closed_lists.h"

int count_nodes(box_list_s *list)
{
    box_list_s *node = list;
    int count = 0;
    while (node != NULL) {
        count += 1;
        node = node->next;
    }
    return count;
}
