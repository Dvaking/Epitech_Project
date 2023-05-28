/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** my_str_isalpha
*/

#include <stdbool.h>

bool my_str_isalpha(char const *str)
{
    int count = 0;

    if (str[0] == '\0') {
        return false;
    }
    while (str[count] != '\0') {
        if ((str[count] < 'a' || str[count] > 'z') &&
        (str[count] < 'A' || str[count] > 'Z') && (str[count] != ' ')) {
            return false;
        }
        count = count + 1;
    }
    return true;
}
