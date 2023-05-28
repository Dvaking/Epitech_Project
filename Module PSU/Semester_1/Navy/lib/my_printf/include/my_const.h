/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-clara.ortu
** File description:
** my_const
*/

#ifndef MY_CONST_H_
    #define MY_CONST_H_
    #include <stdarg.h>
    #include "my_proto.h"
    const char convrs_specifiers[] = "diouxXeEfFgGaAcspn%bS\0";
    int (*arr_fptr[23])(va_list, convrs_t *) = {&my_put_i, &my_put_i, &my_put_o,
        &my_put_u, &my_put_x, &my_put_xmaj, &my_put_e, &my_put_e,
        &my_put_f, &my_put_f, &my_put_v, &my_put_v, &my_put_v, &my_put_v,
        &my_put_c, &my_put_s, &my_put_v, &my_conv_n, &my_put_percent,
        &my_put_v, &my_put_v, 0};

#endif /* !MY_CONST_H_ */
