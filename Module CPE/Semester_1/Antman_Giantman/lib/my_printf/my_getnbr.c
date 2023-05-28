/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** return the first number of an array
*/

#include <unistd.h>
#include <stdio.h>
int my_compute_power_rec(int nb, int p);

int pos_or_not(char const *str, int *i)
{
    int sign = 0;

    while ((str[*i] == '-') || (str[*i] == '+')) {
        if (str[*i] == '-') {
            sign = sign + 1;
        }
        *i = *i + 1;
    }

    if ((sign % 2) == 1) {
        return (1);
    }
    return (0);
}

int count_numbers(char const *str, int *i, int sign)
{
    int number = 0;
    int tpm_i = *i;
    int final_number_result = 0;
    long int overflow = 0;
    while (str[*i] >= '0' && str[*i] <= '9') {
        *i = *i + 1;
        number = number + 1;
    }
    while (number != 0) {
        overflow = overflow * 10;
        overflow = overflow + (str[tpm_i] - 48);
        number = number - 1;
        tpm_i = tpm_i + 1;
    }
    if (sign == 1)
        overflow = overflow * -1;
    if (overflow > 2147483647 || overflow < -2147483648)
        return (0);
    final_number_result = (int)overflow;
    return (final_number_result);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int sign = 0;

    sign = pos_or_not(str, &i);
    nbr = count_numbers(str, &i, sign);
    if (sign == 1) {
        nbr = nbr * -1;
    }
    return (nbr);
}
