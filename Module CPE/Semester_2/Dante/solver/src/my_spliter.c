/*
** EPITECH PROJECT, 2023
** my_spliter
** File description:
** function that split an str into a word array
** but takes in argument a separator char
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char **malloc_words(char const *str, char separator)
{
    int i = 0;
    int j = 0;
    int count = 0;

    for (i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == separator)
            continue;
        count += 1;
        for (j = i + 1; str[j] != '\0' && str[j] != separator; j += 1);
        i = j - 1;
    }
    char **res = malloc(sizeof(char *) * (count + 1));
    if (res == NULL)
        return NULL;
    return res;
}

char **my_spliter(char const *str, char separator)
{
    int j = 0;
    int k = 0;
    char **res = malloc_words(str, separator);

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == separator)
            continue;
        for (j = i + 1; str[j] != '\0' && str[j] != separator; j += 1);
        res[k] = malloc(sizeof(char) * (j - i + 1));
        if (res[k] == NULL)
            return NULL;
        strncpy(res[k], str + i, j - i);
        res[k][j - i] = '\0';
        k += 1;
        i = j - 1;
    }
    res[k] = NULL;

    return res;
}
