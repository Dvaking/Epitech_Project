/*
** EPITECH PROJECT, 2022
** entry_value
** File description:
** entry_value
*/

#include "my.h"

int take_nbr(char *path, int *val)
{
    long int i = 0;
    long int tmp = 0;
    long int percent = 1;
    int neg = 0;
    int nb = my_strlen(path);
    if (path[0] == '-')
        neg = 1;
    for (int b = nb - 1; nb > neg; b -= 1){
        i = (path[b] - '0') * percent;
        tmp += i;
        percent *= 10;
        nb -= 1;
    }
    if (neg == 1)
        tmp *= -1;
    if (tmp > 2147483647 || tmp < -2147483648)
        return 84;
    *val = tmp;
    return 0;
}
