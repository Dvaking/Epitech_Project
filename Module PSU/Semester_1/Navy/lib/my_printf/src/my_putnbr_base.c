/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** my_putnbr_base
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *my_putnbr_oct(unsigned int deci)
{
    int len_oct = 1;

    while (deci / my_compute_power_rec(8, len_oct) > 7)
        len_oct += 1;

    len_oct += 1;
    char *result = malloc(sizeof(char) * len_oct);

    for (int i = 0; i < len_oct - 1; i += 1)
        result[i] = '0';
    result[len_oct] = '\0';
    for (int power = len_oct - 1; power >= 0; power -= 1){
        result[len_oct - power - 1] = (deci / my_compute_power_rec(8, power))
        % 8 + '0';
    }
    return (result);
}

char *my_putnbr_hexa(unsigned int deci, char maj)
{
    int len_hexa = 1;

    while (deci / my_compute_power_rec(16, len_hexa) > 15)
        len_hexa += 1;

    len_hexa = len_hexa + 1;
    char *result = malloc(sizeof(char) * len_hexa);

    for (int i = 0; i < len_hexa - 1; i += 1)
        result[i] = '0';
    result[len_hexa] = '\0';

    for (int power = len_hexa - 1; power >= 0; power -= 1){
        int digit_hexa = (deci / my_compute_power_rec(16, power)) % 16;
        if (digit_hexa <= 9)
            result[len_hexa - power - 1] = digit_hexa + '0';
        else
            result[len_hexa - power - 1] = digit_hexa - 10 + maj;
    }
    return (result);
}

char *my_putnbr_bin(unsigned int deci)
{
    int len_bin = 1;

    while (deci / my_compute_power_rec(2, len_bin) > 1)
        len_bin += 1;

    len_bin = len_bin + 1;
    char *result = malloc(sizeof(char) * len_bin);

    for (int i = 0; i < len_bin - 1; i += 1)
        result[i] = '0';
    result[len_bin] = '\0';

    for (int power = len_bin - 1; power >= 0; power -= 1){
        result[len_bin - power - 1] = (deci / my_compute_power_rec(2, power))
        % 2 + '0';
    }
    return (result);
}
