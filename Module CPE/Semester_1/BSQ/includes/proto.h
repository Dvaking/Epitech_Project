/*
** EPITECH PROJECT, 2022
** proto
** File description:
** comptain all proto
*/

#include "struct.h"

#ifndef PROTO_H
    #define PROTO_H
                /* proto_lib*/
    int my_strlen(char const *str);
    int my_putstr(char const *str);
    void my_putchar(char c);

            /* proto_programe*/
    void generation_map(map_t *map, int ac, char **av);
    void special_cas(map_t *map, char **av);
    int special_cas_sub(map_t *map, char *buffer, int count);
    void no_square_sub(map_t *map, char **tab);
    void copy_in_tab(map_t *map, char **tab, char *buffer, char **av);
    void redirection(map_t *map, char **tab);
    void find_square(map_t *map, char **tab);
    void no_square(map_t *map, char **tab);
    void display_tab(map_t *map, char **tab);
    void display_tab_with_x(map_t *map, square_t *square, char **tab);
        /*protec && verif*/
    int protection(map_t *map, int ac, int fd);
    int protection_sub(square_t *square);
    int protection_ter(map_t *map, char *buffer, int count);
    int protection_quad(map_t *map, int len, int fd, char *buffer);
    int protection_seis(map_t *map, int ac, char **av);
    int protection_seite(map_t *map, int max_x, int max_y);
    int bigger_square(map_t *map, square_t *square, char **tab);

#endif /* !PROTO_H */
