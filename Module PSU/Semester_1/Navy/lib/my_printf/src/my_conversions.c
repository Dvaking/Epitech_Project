/*
** EPITECH PROJECT, 2022
** my_conversion
** File description:
** Contains fonctions for m_printf conversions
*/

#include <stdarg.h>
#include "my_proto.h"
#include "my_macro.h"

int    my_put_i(va_list list, convrs_t *cvrs)
{
    int nb = va_arg(list, int);
    int nb_len = MAX(get_nbr_len(nb), cvrs->precision);
    int nb_pad = 0;

    if (nb < 0)
        nb_len += 1;
    if (!(cvrs->precision < 0 && cvrs->flag_2) && !(cvrs->flag_3))
        print_padding(cvrs->width - nb_len, ' ');
    nb_pad = cvrs->precision - get_nbr_len(nb);
    if (cvrs->precision < 0 && cvrs->flag_2)
        nb_pad = cvrs->width - nb_len;
    my_put_nbr2(nb, nb_pad);
    if (cvrs->flag_3)
        print_padding(cvrs->width - nb_len + nb_pad, ' ');
    nb_len = MAX(cvrs->width, nb_len);
    return (nb_len);
}

int     my_put_c(va_list list, convrs_t *cvrs)
{
    char c = va_arg(list, int);
    int nb_len = 1;

    if (!(cvrs->flag_3))
        print_padding(cvrs->width - nb_len, ' ');
    my_putchar(c);
    if (cvrs->flag_3)
        print_padding(cvrs->width - nb_len, ' ');
    return (nb_len);
}

int     my_put_s(va_list list, convrs_t *cvrs)
{
    char const *str = va_arg(list, char*);
    int nb_len = my_strlen(str);

    if (!(cvrs->flag_3))
        print_padding(cvrs->width - nb_len, ' ');
    my_putstr(str);
    if (cvrs->flag_3)
        print_padding(cvrs->width - nb_len, ' ');
    return (my_strlen(str));
}

int     my_put_percent(va_list list, convrs_t *conversion)
{
    char c = '%';

    my_putchar(c);
    return (1);
}

int     my_put_v(va_list list, convrs_t *conversion)
{
    return (0);
}
