/*
** EPITECH PROJECT, 2022
** flag_c
** File description:
** flag_c
*/

#include <stdarg.h>
#include "my.h"

int function_c(const char *format, int count, va_list list, int precision)
{
    my_putchar(va_arg(list, int));
    return (0);
}
