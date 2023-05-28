/*
** EPITECH PROJECT, 2022
** move
** File description:
** all relative move
*/

#include <curses.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "proto.h"
#include "struct.h"

static void move_right(charact_box_t *charact_box, char **map, char **map_copy)
{
    if (verif_obstacle(charact_box, map,(charact_box->player.y), \
(charact_box->player.x + 1)) == 1) {
        if (map_copy[charact_box->player.y][charact_box->player.x] == 'O'){
            map[charact_box->player.y][charact_box->player.x] = 'O';
        } else {
            map[charact_box->player.y][charact_box->player.x] = ' ';
        }
        map[charact_box->player.y][charact_box->player.x + 1] = 'P';
        charact_box->player.x += 1;
    }
}

static void move_left(charact_box_t *charact_box, char **map, char **map_copy)
{
    if (verif_obstacle(charact_box, map,(charact_box->player.y), \
(charact_box->player.x - 1)) == 1) {
        if (map_copy[charact_box->player.y][charact_box->player.x] == 'O'){
            map[charact_box->player.y][charact_box->player.x] = 'O';
        } else {
            map[charact_box->player.y][charact_box->player.x] = ' ';
        }
        map[charact_box->player.y][charact_box->player.x - 1] = 'P';
        charact_box->player.x -= 1;
    }
}

static void move_down(charact_box_t *charact_box, char **map, char **map_copy)
{
    if (verif_obstacle(charact_box, map,(charact_box->player.y + 1), \
(charact_box->player.x)) == 1) {
        if (map_copy[charact_box->player.y][charact_box->player.x] == 'O'){
            map[charact_box->player.y][charact_box->player.x] = 'O';
        } else {
            map[charact_box->player.y][charact_box->player.x] = ' ';
        }
        map[charact_box->player.y + 1][charact_box->player.x] = 'P';
        charact_box->player.y += 1;
    }
}

static void move_top(charact_box_t *charact_box, char **map, char **map_copy)
{
    if (verif_obstacle(charact_box, map,(charact_box->player.y - 1), \
(charact_box->player.x)) == 1) {
        if (map_copy[charact_box->player.y][charact_box->player.x] == 'O'){
            map[charact_box->player.y][charact_box->player.x] = 'O';
        } else {
            map[charact_box->player.y][charact_box->player.x] = ' ';
        }
        map[charact_box->player.y - 1][charact_box->player.x] = 'P';
        charact_box->player.y -= 1;
    }
}

void move_player(charact_box_t *charact_box, char **map, int shutdown, \
char **map_copy)
{
    switch (shutdown){
    case KEY_UP:
        move_top(charact_box, map, map_copy);
        break;
    case KEY_DOWN:
        move_down(charact_box, map, map_copy);
        break;
    case KEY_LEFT:
        move_left(charact_box, map, map_copy);
        break;
    case KEY_RIGHT:
        move_right(charact_box, map, map_copy);
        break;
    }
}
