/*
** EPITECH PROJECT, 2022
** windows
** File description:
** all relative tu the window
*/

#include <curses.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "proto.h"
#include "struct.h"


static void check_loose_sub(char **map, int *count, int lines, int cols)
{
    if (map[lines + 1][cols] == '#' && map[lines][cols + 1] == '#' || \
map[lines - 1][cols] == '#' && map[lines][cols - 1] == '#' || \
map[lines + 1][cols] == '#' && map[lines][cols - 1] == '#' || \
map[lines - 1][cols] == '#' && map[lines][cols + 1] == '#') {
    *count += 1;
    }
}

static void check_loose(char **map, int *count, int lines)
{
    for (int cols = 0; map[lines][cols] != '\n'; cols += 1) {
        if (map[lines][cols] == 'X') {
            check_loose_sub(map, count, lines, cols);
        }
    }
}

int check_win_loose(charact_box_t *charact_box, map_size_t *map_size, \
char **map, int *shutdown)
{
    int count = 0;
    int count2 = 0;
    for (int i = 0; i < charact_box->numb_hole; i += 1) {
        if (map[charact_box->hole[i].y][charact_box->hole[i].x] == 'X') {
            count += 1;
        }
    }
    for (int lines = 0; lines < map_size->lines; lines += 1) {
        check_loose(map, &count2, lines);
    }
    if (count == charact_box->numb_hole){
        usleep(1000000);
        return 1;
    }
    if (count2 == charact_box->numb_box){
        *shutdown = 'l';
        return 1;
    }
    return 0;
}

void reset(map_size_t *map_size, charact_box_t *charact_box, \
char **map, char **map_copy)
{
    int count = 0;
    for (int lines = 0; map_size->lines > lines; lines += 1){
        count = 0;
        for (int cols = 0; map_copy[lines][cols] != '\n'; cols += 1) {
            map[lines][cols] = map_copy[lines][cols];
            count += 1;
            charact_box->player.x = charact_box->player.orig_x;
            charact_box->player.y = charact_box->player.orig_y;
        }
        map[lines][count] = '\n';
    }
}
