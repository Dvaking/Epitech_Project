/*
** EPITECH PROJECT, 2023
** solver.c
** File description:
** main function that will solve the maze
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "proto_lib.h"
#include "proto.h"
#include "open_and_closed_lists.h"

box_s edit_box(point_s actual_place, char **map,
box_list_s *parent)
{
    box_s box;
    int nbr_line = 0;
    point_s starting_place = {.x = 0, .y = 0};
    for (; map[nbr_line] != NULL; nbr_line++);
    point_s end_place = {my_strlen(map[0]) - 1, nbr_line - 1};
    box.place = actual_place;
    box.g_cost = distance(starting_place, actual_place);
    box.h_cost = distance(end_place, actual_place);
    box.f_cost = box.g_cost + box.h_cost;
    box.parent = parent;
    return box;
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

int solver(char const *path)
{
    char **map = load_file_in_mem(path);
    if (map == NULL)
        return 84;
    box_list_s *open = NULL;
    box_list_s *closed = NULL;
    int nbr_line = 0;
    for (; map[nbr_line] != NULL; nbr_line++);
    point_s end_place = {my_strlen(map[0]) - 1, nbr_line - 1};
    box_s start = edit_box((point_s){0, 0}, map, NULL);
    map[start.place.y][start.place.x] = 'C';
    if (add_node_end(&open, start) == -1)
        return 84;
    if (a_star(open, closed, map, end_place) == -1)
        return 84;
    free_array(map);
    open = free_node(open);
    closed = free_node(closed);
    return 0;
}
