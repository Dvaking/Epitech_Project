/*
** EPITECH PROJECT, 2023
** a_star
** File description:
** the loop of the algorithm Astar
*/

#include <stdlib.h>
#include <unistd.h>
#include "proto.h"
#include "open_and_closed_lists.h"

int write_output(box_list_s *closed, char **map, int win)
{
    if (win == 1) {
        if (draw_road(closed, map) == -1)
            return -1;
    } else {
        if (write(2, "no solution found", 17) == -1)
            return -1;
    }
}

int a_star(box_list_s *open, box_list_s *closed, char **map,
point_s end_place)
{
    int win = 0;
    while (open != NULL) {
        box_list_s *current = find_lowest_f_cost_in_open(open);
        delete_node(&open, current);
        if (add_node_end(&closed, current->box) == -1)
            return -1;
        map[current->box.place.y][current->box.place.x] = 'C';
        if (current->box.place.x == end_place.x &&
        current->box.place.y == end_place.y) {
            win = 1;
            break;
        }
        if (check_neighbour(&open, map, current) == -1)
            return -1;
    }
    if (write_output(closed, map, win) == -1)
        return -1;
    return 0;
}
