/*
** EPITECH PROJECT, 2023
** find_lowest_f_cost_in_open
** File description:
** find the lowest f_cost value in the open list
*/

#include <stdlib.h>
#include "open_and_closed_lists.h"

box_list_s *find_lowest_f_cost_in_open(box_list_s *open)
{
    box_list_s *node = open;
    box_list_s *lowest_f_cost_box = node;
    while (node->next != NULL) {
        if (node->box.f_cost < lowest_f_cost_box->box.f_cost)
            lowest_f_cost_box = node;
        node = node->next;
    }
    return lowest_f_cost_box;
}

box_list_s *find_lowest_h_cost_in_open(box_list_s *open)
{
    box_list_s *node = open;
    box_list_s *lowest_h_cost_box = node;
    while (node->next != NULL) {
        if (node->box.h_cost < lowest_h_cost_box->box.h_cost)
            lowest_h_cost_box = node;
        node = node->next;
    }
    return lowest_h_cost_box;
}
