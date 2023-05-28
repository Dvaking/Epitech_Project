/*
** EPITECH PROJECT, 2023
** my_word_array_to_list
** File description:
** convert a char ** and place the data in a linked list
*/

#include <unistd.h>
#include <stdlib.h>

#include "linked_list.h"
#include "my.h"

list_t *my_word_array_to_list(list_t *list, char **word_array)
{
    int i = 0;
    while (word_array[i] != NULL) {
        list = add_node_end(list, word_array[i]);
        i += 1;
    }
    return list;
}
