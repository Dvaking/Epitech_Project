/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-marc.mendia
** File description:
** find_and_sort
*/

#include <stdlib.h>
#include <unistd.h>

#include "my.h"
#include "linked_list.h"
#include "proto_fonct.h"
#include "tab_list.h"

static void sort_sub(my_list_t *all_list, int *dist_n, int *dist_p)
{
    if (*dist_n > *dist_p){
        while (*dist_p > 0){
            write(1, "ra ", 3);
            all_list->l_a = rotate(all_list->l_a);
            *dist_p -= 1;
        }
    } else {
        while (*dist_n >= 0){
            all_list->l_a = rotate_right(all_list->l_a);
            write(1, "rra ", 4);
            *dist_n -= 1;
        }
    }
}

static void sort(my_list_t *all_list, element_t *move, \
int *dist_n, int *dist_p)
{
    while (move->previous != NULL) {
        *dist_p += 1;
        move = move->previous;
    }
    if (all_list->l_a->next != NULL){
        sort_sub(all_list, dist_n, dist_p);
    }
    all_list->l_b = push_b(all_list);
    write(1, "pb ", 3);;
}

static void find(my_list_t *all_list, element_t *move, element_t *ppt, \
int count)
{
    int dist_n = 0;
    int dist_p = 0;
    while (move->next != NULL) {
        if (ppt->data > move->data){
            ppt = move;
        }
        move = move->next;
    }
    if (ppt->data > move->data){
            ppt = move;
    }
    move = ppt;
    while (move->next != NULL) {
        dist_n += 1;
        move = move->next;
    }
    move = ppt;
    sort(all_list, move, &dist_n, &dist_p);
}

static void correction_write(my_list_t *all_list)
{
    write(1, "sa sa\n", 6);
    all_list->l_a = swap(all_list->l_a);
    all_list->l_a = swap(all_list->l_a);
}

void find_and_sort(my_list_t *all_list)
{
    int count = 1;
    element_t *begin = all_list->l_a;
    element_t *move = all_list->l_a;
    element_t *ppt = all_list->l_a;
    while (begin != NULL){
        find(all_list, move, ppt, count);
        begin = all_list->l_a;
        move = begin;
        ppt = begin;
    }
    element_t *begin_b = all_list->l_b;
    while (begin_b != NULL) {
        push_a(all_list);
        write(1, "pa ", 3);
        begin_b = all_list->l_b;
    }
    correction_write(all_list);
}
