/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** my_strdup
*/
#include <stdlib.h>
int     my_strlen(char const *str);

char *my_strdup(const char *s)
{
    int count = my_strlen(s);
    char *dest = malloc(sizeof(char) * (count + 1));

    for (int i = 0; i < count; i += 1){
        dest[i] = s[i];
    }
    dest[count] = '\0';
    return (dest);
}
