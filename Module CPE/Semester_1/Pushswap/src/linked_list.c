/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** linked_list
*/

#include <stdlib.h>

#include "tab_list.h"
#include "linked_list.h"
#include "proto.h"
#include "my.h"

element_t *creat_list(char *av, int *val)
{
    element_t *list = malloc(sizeof(element_t));
    if (take_nbr(av, val) == 84)
        return NULL;
    list->data = *val;
    list->next = NULL;
    list->previous = NULL;

    return list;
}

static element_t *creat_block(element_t *tmp, char *av, int *val)
{
    element_t *element = malloc(sizeof(element_t));
    element->data = *val;
    element->next = NULL;
    element->previous = tmp;
    return element;
}

element_t *add_element(int ac, char **av, int *val)
{
    element_t *list = malloc(sizeof(element_t));
    list = creat_list(av[1], val);
    if (list == NULL)
        return NULL;
    element_t *tmp = list;
    for (int b = 2; b < ac; b += 1) {
        if (take_nbr(av[b], val) == 84)
            return NULL;
        tmp->next = creat_block(tmp, av[b], val);
        tmp = tmp->next;
    }
    return list;
}
