/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-clara.ortu
** File description:
** float_cvrs
*/

#include <stdarg.h>
#include "my_proto.h"
#include "my_macro.h"

int my_put_f(va_list list, convrs_t *cvrs)
{
    double nb = va_arg(list, double);
    int int_part = nb;
    int precision = cvrs->precision;
    int nb_len = get_nbr_len(int_part);

    if (precision == -1)
        precision = 6;
    nb_len += precision;
    if (!(cvrs->flag_3))
        print_padding(cvrs->width - nb_len, ' ');
    my_put_float_nbr(nb, precision);
    if (cvrs->flag_3)
        print_padding(cvrs->width - nb_len, ' ');
    return (nb_len);
}

int my_put_e(va_list list, convrs_t *cvrs)
{
    double nb = va_arg(list, double);
    int int_part = nb;
    int precision = cvrs->precision;
    int nb_len = get_nbr_len(int_part);

    if (precision == -1)
        precision = 6;
    nb_len += precision;
    if (!(cvrs->flag_3))
        print_padding(cvrs->width - nb_len, ' ');
    my_put_sci_nbr(nb, precision);
    if (cvrs->flag_3)
        print_padding(cvrs->width - nb_len, ' ');
    return (nb_len);
}
