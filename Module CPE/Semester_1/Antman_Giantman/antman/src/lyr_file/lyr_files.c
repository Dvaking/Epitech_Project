/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** lyr_file
*/

#include <unistd.h>
#include <stdlib.h>

#include "proto_antman.h"
#include "proto_lib.h"

int lyr_files(char *filepath)
{
    list_t *list_setence;
    list_setence = NULL;
    int key = '!';
    char *str = load_file_in_mem(filepath);
    if (str == NULL)
        return 1;
    char **setence = split_my_str(str);
    list_setence = my_word_array_to_list(list_setence, setence);
    if (compress_setence(list_setence, &key) == 1)
        return 1;
    print_node(list_setence);
    free(str);
    free_array(setence);
    free_list(list_setence);
    return 0;
}
