/*
** EPITECH PROJECT, 2022
** proto
** File description:
** proto
*/

#include "tab_list.h"
#include "linked_list.h"

#ifndef PROTO_H
    #define PROTO_H

        /* proto program */
    /* entry_value.c */
    int take_nbr(char *path, int *val);

    /* linked_list.c */
    element_t *add_element(int ac, char **av, int *val);

    /* find_and_sort.c */
    void find_and_sort(my_list_t *all_list);

    /* protection.c */
    int protection_num(int ac, char **av);

#endif /* !PROTO_H */
