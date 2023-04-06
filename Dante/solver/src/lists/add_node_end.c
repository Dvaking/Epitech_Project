/*
** EPITECH PROJECT, 2022
** add node end
** File description:
** add a node in the end of a linked list
*/

#include <stdlib.h>
#include "open_and_closed_lists.h"
#include "proto.h"
#include <math.h>

int add_node_end(box_list_s **list, box_s box)
{
    box_list_s *node = *list;
    box_list_s *new_node = create_list(box);
    if (new_node == NULL)
        return -1;
    if (*list == NULL) {
        *list = create_list(box);
        return 0;
    }
    while (node->next != NULL)
        node = node->next;
    node->next = new_node;
    new_node->next = NULL;
    return 0;
}
