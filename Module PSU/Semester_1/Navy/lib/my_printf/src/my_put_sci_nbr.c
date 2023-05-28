/*
** EPITECH PROJECT, 2022
** put int the style d.dde+-dd
** File description:
** flag e
*/

#include "my_proto.h"
#include <stdio.h>

int my_put_sci_nbr_part2(int int_part)
{
    if (int_part < 1 && int_part > -1){
        my_putstr("e-");
    } else {
        my_putstr("e+");
    }
    return (0);
}

int my_put_sci_nbr(double nb, int precision)
{
    int int_part = nb;
    if (nb == int_part)
        return (nb);
    int i = 0;
    for (i; nb >= 10 || nb <= -10; i += 1){
        nb = nb / 10;
    }
    for (i; nb < 1 && nb > - 1; i += 1){
        nb = nb * 10;
    }
    my_put_float_nbr(nb, precision);
    my_put_sci_nbr_part2(int_part);
    if (i < 10)
        my_put_nbr(0);
    my_put_nbr(i);
    return (0);
}
