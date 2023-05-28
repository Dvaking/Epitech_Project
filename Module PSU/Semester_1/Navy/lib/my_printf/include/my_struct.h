/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-clara.ortu
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_
    #include <stdbool.h>
    typedef struct convrs_s {
        bool flag_1;
        bool flag_2;
        bool flag_3;
        bool flag_4;
        bool flag_5;
        int width;
        int precision;
        char *len_mod;
        int len_printed;
    } convrs_t;

#endif /* !MY_STRUCT_H_ */
