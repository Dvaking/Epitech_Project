/*
** EPITECH PROJECT, 2022
** my_str_is_num
** File description:
** my_str_isnum
*/

#include <stdbool.h>

bool my_str_isnum(char const *str)
{
    int count = 0;

    if (str[0] == '\0') {
        return false;
    }
    while (str[count] != '\0') {
        if ((str[count] < '0' || str[count] > '9') && (str[count] != ' ')) {
            return false;
        }
        count = count + 1;
    }
    return true;
}
