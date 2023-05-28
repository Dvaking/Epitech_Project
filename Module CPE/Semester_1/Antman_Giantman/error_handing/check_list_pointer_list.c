/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** check_list_pointer_list
*/

#include <unistd.h>

#include "linked_list.h"


int verification_pointer(list_t *move, list_t *selectioned, list_t *comparison)
{
    if (move == NULL)
        return 1;
    if (selectioned == NULL)
        return 1;
    if (comparison == NULL)
        return 1;
}

int verification_pointer_decompress(list_t *move, list_t *comparison)
{
    if (move == NULL)
        return 1;
    if (comparison == NULL)
        return 1;
}
