/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** projet pushswap
*/

#include <stdlib.h>
#include <unistd.h>

#include "tab_list.h"
#include "linked_list.h"
#include "proto_fonct.h"
#include "proto.h"
#include "my.h"

int pushswap(int ac, char **av)
{
    
    // INIT
    int val = 0;
    my_list_t *all_list = malloc(sizeof(my_list_t));
    if (all_list == NULL)
        return 84;
    all_list->l_a = add_element(ac, av, &val);
    if (all_list->l_a == NULL)
        return 84;
    all_list->l_b = NULL;

    find_and_sort(all_list);
    return 0;
}

int main(int argc, char **argv)
{
    // return value = error_handling()
    // if (error_handling_status =  error_handling() == KO)
    //  return error_handling
    int return_value = 0;
    if (argc < 2){
        write(1, "\n", 1);
        return 0;
    }
    if (argc < 3){
        write(1, "\n", 1);
        return 0;
    }
    if (protection_num(argc, argv) == 84){
        return 84;
    } else {
        return_value = pushswap(argc, argv);
    }
    return return_value;
}
