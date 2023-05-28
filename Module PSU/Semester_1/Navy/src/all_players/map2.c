/*
** EPITECH PROJECT, 2023
** map player 2
** File description:
** map player 2
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <struct.h>
#include <unistd.h>

#include "proto.h"
#include "proto_lib.h"

static t_player *create_5_boat(char *line, int i, t_player *my_player2)
{
    my_player2->x5 = create_x_numb(line[2]);
    my_player2->i5 = create_i_numb(line[3]);
    my_player2->x5f = create_x_numb(line[5]);
    my_player2->i5f = create_i_numb(line[6]);
}

void create_struct_boat2(char *line, int i, t_player *my_player2)
{
    switch (i) {
        case 1 :
            my_player2->x2 = create_x_numb(line[2]);
            my_player2->i2 = create_i_numb(line[3]);
            my_player2->x2f = create_x_numb(line[5]);
            my_player2->i2f = create_i_numb(line[6]);
        case 2 :
            my_player2->x3 = create_x_numb(line[2]);
            my_player2->i3 = create_i_numb(line[3]);
            my_player2->x3f = create_x_numb(line[5]);
            my_player2->i3f = create_i_numb(line[6]);
        case 3 :
            my_player2->x4 = create_x_numb(line[2]);
            my_player2->i4 = create_i_numb(line[3]);
            my_player2->x4f = create_x_numb(line[5]);
            my_player2->i4f = create_i_numb(line[6]);
        case 4 :
            my_player2 = create_5_boat(line, i, my_player2);
    }
}
