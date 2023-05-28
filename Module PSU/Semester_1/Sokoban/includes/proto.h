/*
** EPITECH PROJECT, 2022
** proto
** File description:
** proto
*/
#include <curses.h>

#include "struct.h"

#ifndef PROTO_H
    #define PROTO_H

            /* proto lib */
    int my_strlen(char const *str);

            /* proto program */
        /* sokoban.c */
    void sokoban_quad(map_size_t *map_size, WINDOW *win, char **map);

        /* map_size.c */
    void get_size(map_size_t *map_size, char *buffer);

        /* copy_in_tab.c */
    void copy_in_tab(map_size_t *map_size, charact_box_t *charact_box, \
    char **map, char *buffer);
    void copy_in_tab_sub(map_size_t *map_size, charact_box_t *charact_box, \
    char **map, char **map_copy);
    void numb_hole_box(charact_box_t *charact_box, char *buffer);

        /* move_player.c && move_player_sub.c */
    void move_correction(charact_box_t *charact_box , char **map);
    void move_player(charact_box_t *charact_box, char **map, int shutdown, \
    char **map_copy);

        /* move_box */
    int move_boxe(charact_box_t *charact_box, char **map, int y, int x);

        /* condition.c && protection.c */
    int verif_obstacle(charact_box_t *charact_box, char **map, int y, int x);
    int pos_wall(char **map, int y, int x);
    int protection(int fd, char *buffer, map_size_t *map_size, \
    charact_box_t *charact_box);

        /* windows.c */
    int check_win_loose(charact_box_t *charact_box, map_size_t *map_size, \
    char **map, int *shutdown);
    void reset(map_size_t *map_size, charact_box_t *charact_box, \
    char **map, char **map_copy);

        /* display.c */
    void display(map_size_t *map_size, WINDOW *win, char **map);
    void check_len(map_size_t *map_size, WINDOW *win);
    void display_h(void);

        /*free_destroy.c */
    void free_map(map_size_t *map_size, char **map, char **map_copy);
    void free_struct_buff_fd(map_size_t *map_size, charact_box_t *charact_box,\
    char *buffer, int fd);

#endif /* !PROTO_H */
