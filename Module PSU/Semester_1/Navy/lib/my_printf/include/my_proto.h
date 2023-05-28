/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-clara.ortu
** File description:
** my_proto
*/

#ifndef MY_PROTO_H_
    #define MY_PROTO_H_
    #include <stdarg.h>
    #include "my_struct.h"
    #include "my.h"
    void   get_convrs(char const *format, convrs_t *convrs, int *arr_ind,\
int len_print);
    int    my_put_i(va_list, convrs_t *);
    int    my_put_o(va_list, convrs_t *);
    int    my_put_u(va_list, convrs_t *);
    int    my_put_x(va_list, convrs_t *);
    int    my_put_xmaj(va_list, convrs_t *);
    int    my_put_c(va_list, convrs_t *);
    int    my_put_s(va_list, convrs_t *);
    int    my_put_e(va_list, convrs_t *);
    int    my_put_f(va_list, convrs_t *);
    int    my_conv_n(va_list, convrs_t *);
    int    my_put_v(va_list, convrs_t *);
    int    my_put_percent(va_list, convrs_t *);
    char   *my_putnbr_hexa(unsigned int deci, char maj);
    char   *my_putnbr_oct(unsigned int deci);
    int    my_put_nbr2(int nb, int nb_pad);
    int    my_put_uns_nbr(unsigned int nb);
    int    get_uns_nbr_len(unsigned int nb);
    int    my_put_float_nbr(double nb, int precision);
    int    my_put_sci_nbr(double nb, int precision);
    int    get_nbr_len(int nb);
    int    print_padding(int nb_pad, char c);
    int     my_putstr(char const *str);
#endif /* !MY_PROTO_H_ */
