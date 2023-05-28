/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marc.mendia
** File description:
** swap
*/

#include <stdlib.h>

#include "linked_list.h"
#include "tab_list.h"

static int numb(element_t *list)
{
    int count = 1;
    element_t *tmp = list;
    while (tmp->next != NULL){
        count += 1;
        tmp = tmp->next;
    }
    return count;
}

element_t *swap(element_t *list)
{
    element_t *e1 = list;
    element_t *e2 = list->next;
    int ac = numb(list);
    if (ac == 2){
        e1->previous = e2;
        e1->next = NULL;
        e2->next = e1;
        e2->previous = NULL;
    } else if (ac >= 3){
        element_t *e3 = list->next->next;
        e2->next = e1;
        e2->previous = NULL;
        e1->previous = e2;
        e1->next = e3;
        e3->previous = e1;
    }
    list = e2;
    return list;
}

void swap_all(my_list_t *all_list)
{
    if (all_list->l_b == NULL){
        all_list->l_a = swap(all_list->l_a);
        all_list->l_b = NULL;
        return;
    }
    if (all_list->l_a == NULL){
        all_list->l_b = swap(all_list->l_b);
        all_list->l_a = NULL;
        return;
    }
    all_list->l_a = swap(all_list->l_a);
    all_list->l_b = swap(all_list->l_b);
}
