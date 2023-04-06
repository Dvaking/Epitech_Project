/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#include <stdarg.h>

#ifndef my
    #define my

    int my_printf(const char *format, ...);
    int function_c(const char *format, int count, va_list list, int precision);
    int function_i(char const *format, int count, va_list list, int precision);
    int function_s(const char *format, int count, va_list list, int precision);
    int function_o(char const *format, int count, va_list list, int precision);
    int function_e(char const *format, int count, va_list list, int precision);
    int function_f(const char *format, int count, va_list list, int precision);
    int function_u(char const *format, int count, va_list list, int precision);
    int function_d(const char *format, int count, va_list list, int precision);
    int function_n(char const *format, int count, va_list list, int precision);
    int function_x(char const *format, int count, va_list list, int precision);
    int function_percentage(char const *format, int count, va_list list,
    int precision);
    int function_e_maj(const char *format, int count, va_list list,
    int precision);
    int function_f_maj(const char *format, int count, va_list list,
    int precision);
    int function_x_maj(char const *format, int count, va_list list,
    int precision);
    int find_flag(char my_flag, int count, char const *format, va_list list);
    void my_putchar(char c);
    int my_put_nbr(int nb);
    int my_strlen(char const *str);
    int count_digit(unsigned int nbr_tpm);
    char **my_str_to_word_array(char const *str, char separator);
    int my_str_isalpha(char const *str);
    int my_str_isnum(char const *str);
    int my_getnbr(char const *str);


#endif /* !my */
