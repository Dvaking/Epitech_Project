/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** recreat sokoban game
*/

#include <stdio.h>

#include <curses.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "proto.h"
#include "struct.h"

void sokoban_quad(map_size_t *map_size, WINDOW *win, char **map)
{
    for (int i = 0; i < map_size->lines; i += 1){
        mvwaddstr(win, ((LINES / 2) + i) - (map_size->lines / 2), \
        ((COLS / 2)) - (map_size->columns / 2), map[i]);
    }
}

static int sokoban_ter(map_size_t *map_size, charact_box_t *charact_box, \
char **map, char **map_copy)
{
    WINDOW *win = initscr();
    keypad(win, TRUE);
    int shutdown = 'a';
    copy_in_tab_sub(map_size, charact_box, map, map_copy);
    while (check_win_loose(charact_box, map_size, map, &shutdown) != 1) {
        wclear(win);
        check_len(map_size, win);
        display(map_size, win, map);
        shutdown = getch();
        if (shutdown == ' ')
            reset(map_size, charact_box, map, map_copy);
        move_player(charact_box, map, shutdown, map_copy);
        wclear(win);
        display(map_size, win, map);
    }
    endwin();
    if (shutdown == 'l')
        return 1;
    return 0;
}

static int my_sokoban_sub(map_size_t *map_size, charact_box_t *charact_box, \
char *buffer)
{
    int return_value = 0;
    char **map;
    char **map_copy;
    map = malloc(sizeof(char *) * map_size->lines + 1);
    map_copy = malloc(sizeof(char *) * map_size->lines + 1);
    for (int lines = 0; lines < map_size->lines; lines += 1){
        map[lines] = malloc(sizeof(char) * map_size->columns + 1);
        map_copy[lines] = malloc(sizeof(char) * map_size->columns + 1);
    }
    copy_in_tab(map_size, charact_box, map, buffer);
    return_value = sokoban_ter(map_size, charact_box, map, map_copy);
    free_map(map_size, map, map_copy);
    return return_value;
}

int my_sokoban(char **av)
{
    struct stat s;
    stat(av[1], &s);
    map_size_t *map_size = malloc(sizeof(map_size_t));
    charact_box_t *charact_box = malloc(sizeof(charact_box_t));
    char *buffer = malloc(sizeof(char) * s.st_size + 1);
    buffer[s.st_size] = '\0';
    int fd = open(av[1], O_RDONLY);
    int len = read(fd, buffer, s.st_size);
    close(fd);
    numb_hole_box(charact_box, buffer);
    charact_box->hole = malloc(sizeof(coord_t) * charact_box->numb_hole);
    get_size(map_size, buffer);
    int return_value = protection(fd, buffer, map_size, charact_box);
    if (return_value != 84){
        return_value = my_sokoban_sub(map_size, charact_box, buffer);
        free_struct_buff_fd(map_size, charact_box, buffer, fd);
    }
    return return_value;
}

int main(int argc, char **argv)
{
    int return_value = 0;
    if (argc != 2) {
        return 84;
    } else {
        if (argv[1][0] == '-'){
            display_h();
        } else {
        return_value = my_sokoban(argv);
        }
    }
    return return_value;
}
