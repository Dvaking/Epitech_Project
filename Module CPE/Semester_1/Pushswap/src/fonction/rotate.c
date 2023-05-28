/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marc.mendia
** File description:
** rotate
*/

#include <stdlib.h>

#include "linked_list.h"
#include "tab_list.h"
#include "proto_fonct.h"

element_t *rotate_right(element_t *list)
{
    int count = 2;
    element_t *e1 = list;
    element_t *e2 = list;
    element_t *e3 = list->next;
    while (e3->next != NULL) {
        count += 1;
        e2 = e2->next;
        e3 = e3->next;
    }
    if (count == 2){
        list = swap(list);
        return list;
    }
    e3->next = e1;
    e1->previous = e3;
    e3->previous = NULL;
    e2->next = NULL;
    list = e3;
    return list;
}

void rotate_right_all(my_list_t *all_list)
{
    if (all_list->l_b == NULL){
        all_list->l_a = rotate_right(all_list->l_a);
        all_list->l_b = NULL;
        return;
    }
    if (all_list->l_a == NULL){
        all_list->l_b = rotate_right(all_list->l_b);
        all_list->l_a = NULL;
        return;
    }
    all_list->l_a = rotate_right(all_list->l_a);
    all_list->l_b = rotate_right(all_list->l_b);
}

element_t *rotate(element_t *list)
{
    int count = 1;
    element_t *e1 = list;
    element_t *e2 = list->next;
    element_t *e3 = list;
    while (e3->next != NULL) {
        count += 1;
        e3 = e3->next;
    }
    if (count == 2){
        list = swap(list);
        return list;
    }
    e3->next = e1;
    e1->previous = e3;
    e1->next = NULL;
    e2->previous = NULL;
    list = e2;
    return list;
}

void rotate_all(my_list_t *all_list)
{
    if (all_list->l_b == NULL){
        all_list->l_a = rotate(all_list->l_a);
        all_list->l_b = NULL;
        return;
    }
    if (all_list->l_a == NULL){
        all_list->l_b = rotate(all_list->l_b);
        all_list->l_a = NULL;
        return;
    }
    all_list->l_a = rotate(all_list->l_a);
    all_list->l_b = rotate(all_list->l_b);
}
