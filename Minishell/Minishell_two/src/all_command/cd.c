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

static int cd_checker(base_minishell_t *base, char **tab)
{
    if (my_strncmp_spe("-", tab[1], 1) == OK &&
    tab[1][1] == '\0'){
        if (return_old_folder(base) != OK)
            return KO;
        return OK;
    }
    if (my_strncmp("~", tab[1], 1) == OK &&
    (tab[1][1] == '\0' || tab[1][1] == '/')){
        if (move_from_home(base, tab) != OK)
            return KO;
        return OK;
    }
    if (move_in_folder(base, tab[1]) != OK)
            return KO;
    return OK;
}

int cd_reprogramming(base_minishell_t *base, char **tab)
{
    int i = 0;
    for (i = 0; tab[i] != NULL; i += 1);
    if (i == 1){
        move_to_home(base);
    } else if (i > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return 1;
    } else {
        cd_checker(base, tab);
    }
    return OK;
}
