/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** lyr_file
*/

#include <unistd.h>
#include <stdlib.h>

#include "proto_lib.h"
#include "proto_giantman.h"

int lyr_file(char *filepath)
{
    list_t *list_setence;
    list_setence = NULL;
    char *str = load_file_in_mem(filepath);
    if (str == NULL)
        return 1;
    char **setence = split_my_str(str);
    list_setence = my_word_array_to_list(list_setence, setence);
    if (list_setence == NULL)
        return 1;
    if (decompress_setence(list_setence) == 1)
        return 1;
    print_node(list_setence);
    free(str);
    free_array(setence);
    free_list(list_setence);
    return 0;
}
