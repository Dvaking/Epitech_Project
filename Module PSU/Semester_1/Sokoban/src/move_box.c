/*
** EPITECH PROJECT, 2022
** move_box
** File description:
** move_of_box
*/

#include "proto.h"
#include "struct.h"

int move_boxe(charact_box_t *charact_box, char **map, int y, int x)
{
    if (pos_wall(map, charact_box->mov_box_y, charact_box->mov_box_x) == 1){
        if (map[charact_box->mov_box_y][charact_box->mov_box_x] != 'X'){
            map[y][x] = ' ';
            map[charact_box->mov_box_y][charact_box->mov_box_x] = 'X';
        return 1;
        }
    }
    return 0;
}
