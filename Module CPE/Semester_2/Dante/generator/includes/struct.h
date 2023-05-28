/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

        /* tableau */
    typedef struct tab_data{
        int x_max;
        int y_max;
        int rm_wall;
        char **tab;
    } tab_data_t;

    typedef struct move_s {
        int x;
        int y;
    }move_s_t;

#endif /* !STRUCT_H_ */
