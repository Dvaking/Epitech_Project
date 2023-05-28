/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marc.mendia
** File description:
** push
*/

#include <stdlib.h>

#include "linked_list.h"
#include "tab_list.h"

static element_t *push_a_sub(element_t *list_a, element_t *e1)
{
    if (list_a == NULL){
        list_a = e1;
        e1->next = NULL;
        e1->previous = NULL;
        return list_a;
    }
    element_t *ea1 = list_a;
    e1->previous = NULL;
    e1->next = ea1;
    ea1->previous = e1;
    list_a = e1;
    return list_a;
}

element_t *push_a(my_list_t *all_list)
{
    if (all_list->l_b == NULL)
        return NULL;
    int count = 1;
    element_t *e1 = all_list->l_b;
    element_t *e2 = all_list->l_b;
    while (e2->next != NULL){
        count += 1;
        e2 = e2->next;
    }
    if (count < 2){
        all_list->l_a = push_a_sub(all_list->l_a, e1);
        all_list->l_b = NULL;
    } else {
        e2 = all_list->l_b->next;
        all_list->l_a = push_a_sub(all_list->l_a, e1);
        all_list->l_b = e2;
    }
    return all_list->l_a;
}

static element_t *push_b_sub(element_t *list_b, element_t *e1)
{
    if (list_b == NULL){
        list_b = e1;
        e1->next = NULL;
        e1->previous = NULL;
        return list_b;
    }
    element_t *ea1 = list_b;
    e1->previous = NULL;
    e1->next = ea1;
    ea1->previous = e1;
    list_b = e1;
    return list_b;
}

element_t *push_b(my_list_t *all_list)
{
    if (all_list->l_a == NULL)
        return NULL;
    int count = 1;
    element_t *e1 = all_list->l_a;
    element_t *e2 = all_list->l_a;
    while (e2->next != NULL){
        count += 1;
        e2 = e2->next;
    }
    if (count < 2){
        all_list->l_b = push_b_sub(all_list->l_b, e1);
        all_list->l_a = NULL;
    } else {
        e2 = all_list->l_a->next;
        all_list->l_b = push_b_sub(all_list->l_b, e1);
        e2->previous = NULL;
        all_list->l_a = e2;
    }
    return all_list->l_b;
}
