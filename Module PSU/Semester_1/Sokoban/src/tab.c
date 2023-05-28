/*
** EPITECH PROJECT, 2022
** copy_in_tab
** File description:
** copy a file in a tab
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "proto.h"
#include "struct.h"

void numb_hole_box(charact_box_t *charact_box, char *buffer)
{
    int b = 0;
    charact_box->numb_hole = 0;
    charact_box->numb_box = 0;
    for (int lines = 0; buffer[b] != '\0'; lines += 1) {
        if (buffer[b] == 'O'){
            charact_box->numb_hole += 1;
        }
        if (buffer[b] == 'X'){
            charact_box->numb_box += 1;
        }
        b += 1;
    }
}

static void co_hole(charact_box_t *charact_box, char **map, int lines, \
int *count)
{
    for (int cols = 0; map[lines][cols] != '\n'; cols += 1) {
        if (map[lines][cols] == 'O') {
            charact_box->hole[*count].x = cols;
            charact_box->hole[*count].y = lines;
            *count += 1;
        }
    }
}

static void co_player(charact_box_t *charact_box, char *buffer, int lines, \
int b)
{
    for (int cols = 0; buffer[b] != '\n'; cols += 1) {
        if (charact_box->player.x > 0) {
            return;
        }
        if (buffer[b] == 'P'){
            charact_box->player.x = cols;
            charact_box->player.y = lines;
            charact_box->player.orig_x = cols;
            charact_box->player.orig_y = lines;
            return;
        }
        b += 1;
    }
}

void copy_in_tab_sub(map_size_t *map_size, charact_box_t *charact_box, \
char **map, char **map_copy)
{
    int count = 0;
    for (int lines = 0; map_size->lines > lines; lines += 1){
        count = 0;
        for (int cols = 0; map[lines][cols] != '\n'; cols += 1) {
            map_copy[lines][cols] = map[lines][cols];
            count += 1;
        }
        map_copy[lines][count] = '\n';
    }
    count = 0;
    for (int lines = 0; lines < map_size->lines; lines += 1){
        co_hole(charact_box, map, lines, &count);
    }
}

void copy_in_tab(map_size_t *map_size, charact_box_t *charact_box, \
char **map, char *buffer)
{
    int b = 0;
    int count = 0;
    charact_box->player.x = 0;
    charact_box->player.y = 0;
    for (int lines = 0; lines < map_size->lines ; lines += 1){
        co_player(charact_box, buffer, lines, b);
        count = 0;
        for (int cols = 0; buffer[b] != '\n'; cols += 1) {
            map[lines][cols] = buffer[b];
            count += 1;
            b += 1;
        }
        map[lines][count] = '\n';
        b += 1;
    }
}
