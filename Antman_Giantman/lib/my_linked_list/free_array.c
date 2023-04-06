/*
** EPITECH PROJECT, 2023
** free_array
** File description:
** free a word array
*/

#include <stdlib.h>

void free_array(char **line_array)
{
    for (int i = 0; line_array[i] != NULL; i += 1)
        free(line_array[i]);
    free(line_array);
}
