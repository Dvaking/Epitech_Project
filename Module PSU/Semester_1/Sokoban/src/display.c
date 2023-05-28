/*
** EPITECH PROJECT, 2022
** display
** File description:
** all relative to display
*/

#include <curses.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "proto.h"
#include "struct.h"

void check_len(map_size_t *map_size, WINDOW *win)
{
    if (COLS < map_size->columns || LINES < map_size->lines){
        wclear(win);
        mvwaddstr(win, LINES / 2, (COLS / 2) - my_strlen("error"), \
        "error");
        wrefresh(win);
    }
}

void display(map_size_t *map_size, WINDOW *win, char **map)
{
    if (COLS > map_size->columns && LINES > map_size->lines){
        sokoban_quad(map_size, win, map);
        wrefresh(win);
    }
}

void display_h(void)
{
    write(1, "USAGE\n     ./my_sokoban map\nDESCRIPTION\n", 41);
    write(1, "     map file representing the warehouse map, containing '#' \
for walls,\n", 73);
    write(1, "         'P' for the player, 'X' for boxes and 'O' \
for storage locations.\n", 75);
}
