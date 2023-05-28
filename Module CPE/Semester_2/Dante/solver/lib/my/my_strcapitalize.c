/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** A faire
*/

#include <stdio.h>

char *my_strlowcase(char *str);

char *conditions_min(char *str, int count)
{
    int c = str[count - 1];
    if (c > '9' && c < 'A' || c >= 0 && c < '0') {
        str[count] = str[count] - 32;
    }
    return str;
}

char *my_strcapitalize(char *str)
{
    int count = 0;
    char c = str[count - 1];
    my_strlowcase(str);
    while (str[count] != '\0') {
        conditions_min(str, count);
        count = count + 1;
    }
    return (str);
}
