/*
** EPITECH PROJECT, 2023
** check_neighbour
** File description:
** check the neighbour and put into lists
*/

#include "open_and_closed_lists.h"
#include "proto.h"
#include <stdlib.h>


static int check_neighbour_right(box_list_s **open,
char **map, box_list_s *current)
{
    if (map[current->box.place.y][current->box.place.x + 1] != '\0') {
        if (map[current->box.place.y][current->box.place.x + 1] == '*') {
            point_s place_neighbour = {current->box.place.x + 1,
            current->box.place.y};
            box_s neighbour_box = edit_box(place_neighbour, map, current);
            add_node_end(open, neighbour_box);
            map[current->box.place.y][current->box.place.x + 1] = 'O';
        }
    }
    return 0;
}

static int check_neighbour_left(box_list_s **open,
char **map, box_list_s *current)
{
    if (current->box.place.x != 0) {
        if (map[current->box.place.y][current->box.place.x - 1] == '*') {
            point_s place_neighbour = {current->box.place.x - 1,
            current->box.place.y};
            box_s neighbour_box = edit_box(place_neighbour, map, current);
            add_node_end(open, neighbour_box);
            map[current->box.place.y][current->box.place.x - 1] = 'O';
        }
    }
    return check_neighbour_right(open, map, current);
}

static int check_neighbour_down(box_list_s **open,
char **map, box_list_s *current)
{
    if (map[current->box.place.y + 1] != NULL) {
        if (map[current->box.place.y + 1][current->box.place.x] == '*') {
            point_s place_neighbour = {current->box.place.x,
            current->box.place.y + 1};
            box_s neighbour_box = edit_box(place_neighbour, map, current);
            add_node_end(open, neighbour_box);
            map[current->box.place.y + 1][current->box.place.x] = 'O';
        }
    }
    return check_neighbour_left(open, map, current);
}

int check_neighbour(box_list_s **open, char **map,
box_list_s *current)
{
    if (current->box.place.y != 0) {
        if (map[current->box.place.y - 1][current->box.place.x] == '*') {
            point_s place_neighbour = {current->box.place.x,
            current->box.place.y - 1};
            box_s neighbour_box = edit_box(place_neighbour, map, current);
            add_node_end(open, neighbour_box);
            map[current->box.place.y - 1][current->box.place.x] = 'O';
        }
    }
    return check_neighbour_down(open, map, current);
}
