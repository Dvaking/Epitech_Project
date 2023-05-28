/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marc.mendia
** File description:
** proto_fonc
*/

#include "linked_list.h"
#include "tab_list.h"

#ifndef FONCT_H
    #define FONCT_H

    /* swap.c */
    element_t *swap(element_t *list);
    void swap_all(my_list_t *all_list);

    /* rotate.c */
    element_t *rotate(element_t *list);
    void rotate_all(my_list_t *all_list);
    void rotate_right_all(my_list_t *all_list);
    element_t *rotate_right(element_t *list);

    /* push.c */
    element_t *push_a(my_list_t *all_list);
    element_t *push_b(my_list_t *all_list);

#endif /* !FONCT_H */
