/*
** EPITECH PROJECT, 2022
** condition
** File description:
** all condition
*/

#include "proto.h"
#include "struct.h"

static int pos_box_sub(charact_box_t *charact_box, char **map, int y, int x)
{
    int return_value = 0;
    if (charact_box->player.x > x) {
        charact_box->mov_box_x = x - 1;
        charact_box->mov_box_y = y;
        return_value = move_boxe(charact_box, map, y, x);
    }
    if (charact_box->player.x < x) {
        charact_box->mov_box_x = x + 1;
        charact_box->mov_box_y = y;
        return_value = move_boxe(charact_box, map, y, x);
    }
    return return_value;
}

static int pos_box(charact_box_t *charact_box, char **map, int y, int x)
{
    int return_value = 0;
    if (map[y][x] != 'X') {
        return_value = 1;
    }
    if (map[y][x] == 'X'){
        if (charact_box->player.y > y) {
            charact_box->mov_box_x = x;
            charact_box->mov_box_y = y - 1;
            return_value = move_boxe(charact_box, map, y, x);
        }
        if (charact_box->player.y < y) {
            charact_box->mov_box_x = x;
            charact_box->mov_box_y = y + 1;
            return_value = move_boxe(charact_box, map, y, x);
        }
        if (charact_box->player.x < x || charact_box->player.x > x)
            return_value = pos_box_sub(charact_box, map, y, x);
    }
    return return_value;
}

int pos_wall(char **map, int y, int x)
{
    if (map[y][x] == '#') {
        return 0;
    }
    return 1;
}

int verif_obstacle(charact_box_t *charact_box, char **map, int y, int x)
{
    if (pos_wall(map, y, x) == 1){
        if (pos_box(charact_box, map, y, x) == 1){
            return 1;
        }
    }
    return 0;
}
