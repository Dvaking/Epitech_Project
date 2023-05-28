/*
** EPITECH PROJECT, 2022
** struct
** File description:
** struct of file
*/

#ifndef STRUCT_H
    #define STRUCT_H
        /* length of tab */
    typedef struct map {
        int lines;
        int columns;
        int nombre;
    } map_t;

        /* co of the starting square */
    typedef struct square {
        int rows;
        int cols;
        int size;
        int max_x;
        int max_y;
    } square_t;


#endif /* !STRUCT_H */
