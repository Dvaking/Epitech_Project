/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** cd
*/

#include <unistd.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static int cd_checker(interaction_tab_t *all_tab)
{
    if (my_strncmp("-", all_tab->entry[1], 1) == OK &&
    all_tab->entry[1][1] == '\0'){
        if (return_old_folder(all_tab) != OK)
            return KO;
        return OK;
    }
    if (my_strncmp("~", all_tab->entry[1], 1) == OK &&
    (all_tab->entry[1][1] == '\0' || all_tab->entry[1][1] == '/')){
        if (move_from_home(all_tab) != OK)
            return KO;
        return OK;
    }
    if (move_in_folder(all_tab, all_tab->entry[1]) != OK)
            return KO;
    return OK;
}

int cd_reprogramming(interaction_tab_t *all_tab)
{
    int i = 0;
    for (i = 0; all_tab->entry[i] != NULL; i += 1);
    if (i == 1){
        move_to_home(all_tab);
    } else if (i > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return 1;
    } else {
        cd_checker(all_tab);
    }
    return OK;
}
