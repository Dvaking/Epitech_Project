/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** A faire
*/

#include <unistd.h>

#include "macro.h"

int my_str_isalpha(char const *str)
{
    if (str == NULL)
        return KO;
    for (int i = 0; str[i] != '\0'; i += 1){
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return KO;
    }
    return OK;
}
