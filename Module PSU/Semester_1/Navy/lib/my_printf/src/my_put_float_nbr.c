/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "my_proto.h"

int     my_compute_power_rec(int nb, int p);

static void put_last_n_digits(int nb, int n)
{
    if (n > 1){
        put_last_n_digits(nb / 10, n - 1);
    }
    my_putchar((nb % 10) + '0');
}

int my_put_float_nbr_part2(int decimal, int precision, int int_part)
{
    if (decimal / my_compute_power_rec(10, precision) == 2)
        if (int_part > 0)
            return (1);
        else
            return (-1);
    my_put_nbr(int_part);
    return (0);
}

int my_put_float_nbr(double nb, int precision)
{
    int int_part = nb;
    if (nb == int_part)
        return (nb);
    int decimal = int_part;
    if (nb < 0)
        nb = -1 * (nb - decimal - 1);
    else
        nb = nb - decimal + 1;
    for (int count = 0; count != precision + 1 && precision >= 1; count += 1)
        nb = nb * 10;
    decimal = nb;
    if (decimal % 10 >= 5)
        decimal += 10;
    decimal /= 10;
    int_part += my_put_float_nbr_part2(decimal, precision, int_part);
    if (precision == 0)
        return (0);
    my_putchar('.');
    put_last_n_digits(decimal, precision);
    return (int_part);
}
