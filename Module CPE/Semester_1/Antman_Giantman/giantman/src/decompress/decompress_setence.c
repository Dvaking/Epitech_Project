/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** decompress_setence
*/

#include <unistd.h>
#include <stdlib.h>

#include "linked_list.h"
#include "proto_giantman.h"
#include "proto_lib.h"

static int take_key(list_t *list)
{
    int count = 1;
    int key = 0;
    while (list->text[count] != '~'){
        count += 1;
    }
    key = list->text[count + 1];
    return key;
}

static int comparison_sentence_bis(list_t *comparison, char *str, int key)
{
    if (comparison->text[0] == '~' && comparison->text[1] == key &&
    (comparison->text[2] == '\n' || comparison->text[2] == '\0'))
        str_modif(comparison, str);
}

static int comparison_sentence(list_t *comparison, list_t *select)
{
    if (select->text[0] == '~') {
        comparison = comparison->next;
        int key = take_key(select);
        char *str = str_create(select);
        if (str == NULL)
            return 1;
        while (comparison != NULL) {
            comparison_sentence_bis(comparison, str, key);
            comparison = comparison->next;
        }
        return 0;
    }
    return 0;
}

int decompress_setence(list_t *list)
{
    list_t *select = list;
    list_t *comparison = list;
    if (verification_pointer_decompress(select, comparison) == 1)
        return 1;
    while (select != NULL){
        if (comparison_sentence(comparison, select) == 1)
            return 1;
        select = select->next;
        comparison = select;
    }
}
