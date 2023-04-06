/*
** EPITECH PROJECT, 2023
** proto_generator.h
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_
    #include "struct.h"

        /* error handing */
    int check_argc_argv(int argc, char const *const *argv);

        /* all_tab */
    int create_tab_and_fill_it(tab_data_t *tab_data, char const *const *av);
    int take_data(tab_data_t *tab_data, char const *const *av);
    int display_tab(tab_data_t *tab_data);
    int **create_tab_int(tab_data_t *tab_data);
    int imperfect_tab(tab_data_t *tab_data);
    int perfect_or_not(tab_data_t *tab_data, int ac, char const *const *av);
    int add_way(tab_data_t *tab_data, int wall);

        /* maze */
    int move_condition(tab_data_t *tab_data, int **tab, int *y_x, int i);
    int create_maze(tab_data_t *tab_data, int **tab, int y, int x);

    int generator(int ac, char const *const *argv);
    int free_struct(tab_data_t *tab_data);
    int free_all(tab_data_t *tab_data, int **tab);


#endif /* !PROTO_H_ */
