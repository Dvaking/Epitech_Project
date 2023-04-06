/*
** EPITECH PROJECT, 2023
** free_list
** File description:
** free the entire list
*/

#include <stdlib.h>
#include "linked_list.h"

void free_list(list_t *head)
{
    list_t *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
