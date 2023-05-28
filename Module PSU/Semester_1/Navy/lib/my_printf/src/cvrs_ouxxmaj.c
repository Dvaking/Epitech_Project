/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-clara.ortu
** File description:
** cvrs_oxXu
*/

#include <stdarg.h>
#include "my_proto.h"
#include "my_macro.h"

int my_put_o(va_list list, convrs_t *cvrs)
{
    char *str = my_putnbr_oct(va_arg(list, unsigned int));
    int nb_len = MAX(cvrs->precision, my_strlen(str));
    int nb_pad = cvrs->width - nb_len;

    if (!(cvrs->flag_3)) {
        if (cvrs->precision < 0 && cvrs->flag_2)
            print_padding(nb_pad, '0');
        else
            print_padding(nb_pad, ' ');
        }
    nb_len += MAX(nb_pad, 0);
    if (cvrs->precision > my_strlen(str))
        print_padding(cvrs->precision - my_strlen(str), '0');
    my_putstr(str);
    if (cvrs->flag_3)
        print_padding(nb_pad, ' ');
    return (nb_len);
}

int my_put_u(va_list list, convrs_t *cvrs)
{
    unsigned int nb = va_arg(list, unsigned int);
    int nb_len = MAX(cvrs->precision, get_uns_nbr_len(nb));
    int nb_pad = cvrs->width - nb_len;

    if (!(cvrs->flag_3)) {
        if (cvrs->precision < 0 && cvrs->flag_2)
            print_padding(nb_pad, '0');
        else
            print_padding(nb_pad, ' ');
        }
    nb_len += MAX(nb_pad, 0);
    if (cvrs->precision > get_nbr_len(nb))
        print_padding(cvrs->precision - get_uns_nbr_len(nb), '0');
    my_put_uns_nbr(nb);
    if (cvrs->flag_3)
        print_padding(nb_pad, ' ');
    return (nb_len);
}

int my_put_x(va_list list, convrs_t *cvrs)
{
    char *str = my_putnbr_hexa(va_arg(list, unsigned int), 'a');
    int nb_len = MAX(cvrs->precision, my_strlen(str));
    int nb_pad = cvrs->width - nb_len;

    if (!(cvrs->flag_3)) {
        if (cvrs->precision < 0 && cvrs->flag_2)
            print_padding(nb_pad, '0');
        else
            print_padding(nb_pad, ' ');
        }
    nb_len += MAX(nb_pad, 0);
    if (cvrs->precision > my_strlen(str))
        print_padding(cvrs->precision - my_strlen(str), '0');
    my_putstr(str);
    if (cvrs->flag_3)
        print_padding(nb_pad, ' ');
    return (nb_len);
}

int my_put_xmaj(va_list list, convrs_t *cvrs)
{
    char *str = my_putnbr_hexa(va_arg(list, unsigned int), 'A');
    int nb_len = MAX(cvrs->precision, my_strlen(str));
    int nb_pad = cvrs->width - nb_len;

    if (!(cvrs->flag_3)) {
        if (cvrs->precision < 0 && cvrs->flag_2)
            print_padding(nb_pad, '0');
        else
            print_padding(nb_pad, ' ');
        }
    nb_len += MAX(nb_pad, 0);
    if (cvrs->precision > my_strlen(str))
        print_padding(cvrs->precision - my_strlen(str), '0');
    my_putstr(str);
    if (cvrs->flag_3)
        print_padding(nb_pad, ' ');
    return (nb_len);
}

int my_conv_n(va_list list, convrs_t *cvrs)
{
    int *ptr = va_arg(list, int *);
    *ptr = cvrs->len_printed;
    return (0);
}
