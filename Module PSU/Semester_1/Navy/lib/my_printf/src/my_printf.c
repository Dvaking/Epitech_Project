/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** mini_printf
*/

#include <stdarg.h>
#include "my_const.h"
#include "my_macro.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static int which_conversion(char const *format, int i)
{
    for (int specifier = 0; convrs_specifiers[specifier] != 0; specifier += 1)
        if (format[i] == convrs_specifiers[specifier])
            return (specifier);
    return (-1);
}

static int *split_convrs(char const *format, int f_ind)
{
    int *result = malloc(sizeof(int) * 6);
    int ind_width = f_ind;
    int ind_pre = f_ind;
    int ind_lenmod = f_ind;
    int ind_speci = f_ind;

    for (int which_speci = -1; which_speci < 0
        && format[ind_speci] != 0; ind_speci += 1)
        which_speci = which_conversion(format, ind_speci);
    for (ind_width; IS_FLAG(format[ind_width]); ind_width += 1);
    for (ind_pre = ind_width; IS_NUM(format[ind_pre]); ind_pre += 1);
    for (ind_lenmod = ind_pre; IS_NUM(format[ind_lenmod])
        || format[ind_lenmod] == '.'; ind_lenmod += 1);
    result[0] = f_ind;
    result[1] = ind_width;
    result[2] = ind_pre;
    result[3] = ind_lenmod;
    result[4] = ind_speci - 1;
    result[5] = 0;
    return (result);
}

static int *do_conversion(char const *format, int f_ind, va_list list,\
int len_print)
{
    int *result = malloc(sizeof (int) * 3);
    int which_speci = -1;
    int *arr_ind = split_convrs(format, f_ind);
    convrs_t *convrs = malloc(sizeof(convrs_t));

    if (convrs == NULL)
        return (NULL);
    if (result == NULL)
        return (NULL);
    get_convrs(format, convrs, arr_ind, len_print);
    result[0] = arr_fptr[which_conversion(format, arr_ind[4])](list, convrs);
    result[1] = arr_ind[3] + 1 - f_ind;
    free(convrs);
    return (result);
}

int my_printf(const char *format, ...)
{
    int len_printed = 0;
    va_list     list;

    va_start(list, format);

    for (int i = 0; format[i] != '\0'; i += 1){
        if (format[i] == '%'){
            int *arr_conv = do_conversion(format, i + 1, list, len_printed);
            len_printed += arr_conv[0];
            i += arr_conv[1];
            free(arr_conv);
        } else {
            my_putchar(format[i]);
            len_printed += 1;
        }
    }
    va_end(list);
    return (len_printed);
}
