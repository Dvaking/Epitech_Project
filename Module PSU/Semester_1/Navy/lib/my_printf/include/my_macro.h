/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-clara.ortu
** File description:
** macro
*/

#ifndef MACRO_H_
    #define MACRO_H_
    #define MAX(x, y)   ((x) > (y) ? (x) : (y))
    #define IS_FLAG(c)  (((c) == '#' || (c) == '0' || (c) == '-' || (c) == ' ' \
|| (c) == '+') ? true : false)
    #define IS_NUM(c)   (((c) >= '0' && (c) <= '9') ? true : false)
    #define IS_LEN_MOD(c)   (((c) == 'h' || (c) == 'h' || (c) == 'l' \
|| (c) == 'l' || (c) == 'q' || (c) == 'L' || (c) == 'j' || (c) == 'z' \
|| (c) == 'Z' || (c) == 't') ? true : false)

#endif /* !MACRO_H_ */
