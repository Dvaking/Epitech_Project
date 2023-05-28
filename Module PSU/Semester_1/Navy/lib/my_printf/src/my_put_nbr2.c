/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-clara.ortu
** File description:
** my_put_nbr2
*/

#include <stdbool.h>
#include "my_proto.h"

static void put_digits(unsigned int nb)
{
    if (nb >= 10){
        put_digits(nb / 10);
    }
    my_putchar((nb % 10) + '0');
}

int     my_put_nbr2(int nb, int nb_pad)
{
    unsigned int u_nb = 0;
    if (nb < 0) {
        my_putchar('-');
        print_padding(nb_pad, '0');
        u_nb = nb * -1;
        put_digits(u_nb);
    } else {
        print_padding(nb_pad, '0');
        put_digits(nb);
    }
    return (0);
}

int get_nbr_len(int nb)
{
    int nb_len = 0;
    for (int tmp = nb; tmp <= -1 || tmp >= 1; tmp /= 10)
        nb_len += 1;
    return (nb_len);
}

int     my_put_uns_nbr(unsigned int nb)
{
    put_digits(nb);
    return (0);
}

int get_uns_nbr_len(unsigned int nb)
{
    int nb_len = 0;
    for (unsigned int tmp = nb; tmp >= 1; tmp /= 10)
        nb_len += 1;
    return (nb_len);
}
