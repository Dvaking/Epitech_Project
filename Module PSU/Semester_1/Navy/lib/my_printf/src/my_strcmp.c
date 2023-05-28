/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** function compares the two strings s1 and s2
*/
#include "my_proto.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int a = 0;
    int count1 = 0;
    int count2 = 0;

    while (i != my_strlen(s1)){
        count1 = count1 + s1[i];
        i += 1;
    }

    while (a != my_strlen(s2)){
        count2 = count2 + s2[a];
        a += 1;
    }
    return (count1 - count2);
}
