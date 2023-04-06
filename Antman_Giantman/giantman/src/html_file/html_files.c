/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** html_file
*/

#include <unistd.h>
#include <stdlib.h>

#include "proto_giantman.h"
#include "proto_lib.h"

int html_file(char *filepath)
{
    list_t *list_html;
    list_html = NULL;
    char *str = load_file_in_mem(filepath);
    if (str == NULL)
        return 1;
    char **setence = split_my_str(str);
    list_html = my_word_array_to_list(list_html, setence);
    if (decompress_setence(list_html) == 1)
        return 1;
    print_node(list_html);
    free(str);
    free_array(setence);
    free_list(list_html);
    return 0;
}
