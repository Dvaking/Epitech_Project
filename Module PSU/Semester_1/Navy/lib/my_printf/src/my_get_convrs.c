/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-clara.ortu
** File description:
** my_get_convrs
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "my_macro.h"
#include "my_proto.h"

bool *get_flag(char const *format, int ind_flag, int ind_width)
{
    bool *result = malloc(sizeof(bool) * 6);
    result[5] = '\0';
    for (int flag = 0; flag < 5; flag += 1)
        result[flag] = false;
    for (int i = ind_flag; i != ind_width; i += 1)
        if (format[i] == '#')
            result[0] = true;
    for (int i = ind_flag; i != ind_width; i += 1)
        if (format[i] == '0')
            result[1] = true;
    for (int i = ind_flag; i != ind_width; i += 1)
        if (format[i] == '-')
            result[2] = true;
    for (int i = ind_flag; i != ind_width; i += 1)
        if (format[i] == ' ')
            result[3] = true;
    for (int i = ind_flag; i != ind_width; i += 1)
        if (format[i] == '+')
            result[4] = true;
    return (result);
}

int get_width(char const *format, int ind_width, int ind_pre)
{
    int width = 0;
    if (ind_pre - ind_width < 1)
        return (-1);
    for (ind_width; IS_NUM(format[ind_width]); ind_width += 1){
        width = width * 10 + format[ind_width] - '0';
    }
    return (width);
}

int get_precision(char const *format, int ind_pre, int ind_lenmod)
{
    int precision = 0;
    if (ind_lenmod - ind_pre < 1)
        return (-1);
    for (ind_pre += 1; IS_NUM(format[ind_pre]); ind_pre += 1){
        precision = precision * 10 + format[ind_pre] - '0';
    }
    return (precision);
}

void get_convrs(char const *format, convrs_t *convrs, int *arr_ind,\
int len_print)
{
    bool *arr_flag = get_flag(format, arr_ind[0], arr_ind[1]);
    convrs->flag_1 = arr_flag[0];
    convrs->flag_2 = arr_flag[1];
    convrs->flag_3 = arr_flag[2];
    convrs->flag_4 = arr_flag[3];
    convrs->flag_5 = arr_flag[4];
    convrs->width = get_width(format, arr_ind[1], arr_ind[2]);
    convrs->precision = get_precision(format, arr_ind[2], arr_ind[3]);
    convrs->len_printed = len_print;
    free(arr_flag);
}
