/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** compress_setence
*/

#include <unistd.h>
#include <stdlib.h>

#include "linked_list.h"
#include "proto_antman.h"
#include "proto_lib.h"

static int compress(list_t *selectioned, list_t *move, char *str, int *key)
{
    if (selected_setence(selectioned, key) == 1)
        return 1;
    while (move != NULL){
        char *str_replace = create_str(move, 0);
        if (my_strncmp(str, str_replace, my_strlen(str)) == 1)
            modif_str(move, key);
        move = move->next;
    }
    return 0;
}

static int comparison_sentence(list_t *comparison, list_t *selectioned,
list_t *move, int *key)
{
    move = move->next;
    comparison = comparison->next;
    int count_repetition = 0;
    char *str = create_str(selectioned, 0);
    if (str == NULL)
        return 1;
    while (comparison != NULL) {
        if (comparison->text[0] != '~' && (comparison->text[0] != '\n' ||
        comparison->text[my_strlen(comparison->text) + 1] != '\0')){
            char *str_compar = create_str(comparison, 0);
            count_repetition += my_strncmp(str, str_compar, my_strlen(str));
        }
        comparison = comparison->next;
    }
    if (count_repetition > 0){
        if (compress(selectioned, move, str, key) == 1)
            return 1;
        *key += 1;
    }
    return 0;
}

int compress_setence(list_t *list, int *key)
{
    list_t *move = list;
    list_t *selectioned = list;
    list_t *comparison = list;
    if (verification_pointer(move, selectioned, comparison) == 1)
        return 1;
    while (selectioned != NULL){
        if (comparison_sentence(comparison, selectioned, move, key) == 1)
            return 1;
        selectioned = selectioned->next;
        move = selectioned;
        comparison = selectioned;
    }
}
