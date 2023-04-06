/*
** EPITECH PROJECT, 2023
** open_and_closed_lists
** File description:
** two lists that will stock the nodes of the maze
*/

#ifndef OPEN_CLOSE_LIST
    #define OPEN_CLOSE_LIST

    typedef struct point_t {
        int x;
        int y;
    }point_s;

    typedef struct box_t {
        struct point_t place;
        struct box_list_t *parent;
        int g_cost;
        int h_cost;
        int f_cost;
    }box_s;

    typedef struct box_list_t {
        struct box_list_t *next;
        struct box_t box;
    }box_list_s;

#endif /* OPEN_CLOSE_LIST */
