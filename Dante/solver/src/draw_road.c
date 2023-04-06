/*
** EPITECH PROJECT, 2023
** draw_road.
** File description:
** draw the final road
*/

#include "open_and_closed_lists.h"
#include "proto.h"
#include "proto_lib.h"
#include <stdlib.h>
#include <unistd.h>

static char *replace_char_by_stars(int i, char **map)
{
    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == 'C' || map[i][j] == 'O')
            map[i][j] = '*';
    }
    return map[i];
}

static void draw_last_o(box_list_s *end_node, char **map)
{
    if (map[end_node->box.place.y + 1] != NULL) {
        if (map[end_node->box.place.y + 1][end_node->box.place.x] != 'X') {
            map[end_node->box.place.y + 1][end_node->box.place.x] = 'o';
            return;
        }
    }
    if (map[end_node->box.place.y][end_node->box.place.x + 1] != '\0')
        map[end_node->box.place.y][end_node->box.place.x + 1] = 'o';
}

static int draw_backslash_n(char **map, int j)
{
    if (map[j + 1] != NULL){
        if (write(1, "\n", 1) == -1)
            return -1;
    }
    return 0;
}

int draw_road(box_list_s *closed, char **map)
{
    int i = 0;
    box_list_s *end_node = find_lowest_h_cost_in_open(closed);
    draw_last_o(end_node, map);
    while (end_node->box.place.x != 0 ||
    end_node->box.place.y != 0) {
        map[end_node->box.place.y][end_node->box.place.x] = 'o';
        end_node = end_node->box.parent;
    }
    map[end_node->box.place.y][end_node->box.place.x] = 'o';
    for (; map[i] != NULL; i++)
        map[i] = replace_char_by_stars(i, map);
    map[i - 1][my_strlen(map[0]) - 1] = 'o';
    for (int j = 0; map[j] != NULL; j++) {
        if (write(1, map[j], my_strlen(map[j])) == -1)
            return -1;
        if (draw_backslash_n(map, j) == -1)
            return -1;
    }
    return 0;
}
