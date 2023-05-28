/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** mets une string dans une malloc
*/

#include <stdlib.h>
int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str = 0;
    int count = 0;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[count] != '\0') {
        str[count] = src[count];
        count = count + 1;
    }
    return (str);
}
