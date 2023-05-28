/*
** EPITECH PROJECT, 2022
** struct
** File description:
** struct
*/

#ifndef STRUCT_H
    #define STRUCT_H

    /* map size */
    typedef struct map_size {
        int lines;
        int first_cols;
        int columns;
    } map_size_t;

    /* tableaux coordinate */
    typedef struct coord_t {
        int x;
        int y;
        int orig_x;
        int orig_y;
    } coord_t;

    /* charact && box */
    typedef struct charact_box {
        int mov_box_x;
        int mov_box_y;
        int numb_hole;
        int numb_box;
        coord_t *hole;
        coord_t player;

    } charact_box_t;

#endif /* !STRUCT_H */
