/*
** EPITECH PROJECT, 2023
** map player 1
** File description:
** map player 1
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <struct.h>
#include <unistd.h>

#include "proto.h"
#include "proto_lib.h"

static t_player *create_5_boat(char *line, int i, t_player *p1)
{
    p1->x5 = create_x_numb(line[2]);
    p1->i5 = create_i_numb(line[3]);
    p1->x5f = create_x_numb(line[5]);
    p1->i5f = create_i_numb(line[6]);
}

void create_struct_boat1(char *line, int i, t_player *p1)
{
    switch (i) {
        case 1 :
            p1->x2 = create_x_numb(line[2]);
            p1->i2 = create_i_numb(line[3]);
            p1->x2f = create_x_numb(line[5]);
            p1->i2f = create_i_numb(line[6]);
        case 2 :
            p1->x3 = create_x_numb(line[2]);
            p1->i3 = create_i_numb(line[3]);
            p1->x3f = create_x_numb(line[5]);
            p1->i3f = create_i_numb(line[6]);
        case 3 :
            p1->x4 = create_x_numb(line[2]);
            p1->i4 = create_i_numb(line[3]);
            p1->x4f = create_x_numb(line[5]);
            p1->i4f = create_i_numb(line[6]);
        case 4 :
            p1 = create_5_boat(line, i, p1);
    }
}
