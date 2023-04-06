/*
** EPITECH PROJECT, 2022
** create_list
** File description:
** create a linked list
*/

#include <stdlib.h>
#include "open_and_closed_lists.h"
#include "proto.h"

box_list_s *create_list(box_s box)
{
    box_list_s *list = malloc(sizeof(box_list_s));
    if (list == NULL)
        return NULL;
    list->box = box;
    list->next = NULL;
    return list;
}
