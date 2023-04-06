/*
** EPITECH PROJECT, 2023
** delete node
** File description:
** delete the node
*/

#include <stdlib.h>
#include "open_and_closed_lists.h"

void delete_node(box_list_s **head, box_list_s *node_deleted)
{
    if (*head == NULL || node_deleted == NULL)
        return;
    if (*head == node_deleted) {
        *head = node_deleted->next;
        return;
    }
    box_list_s *node = *head;
    while (node != NULL && node->next != node_deleted)
        node = node->next;
    if (node == NULL)
        return;
    node->next = node_deleted->next;
}
