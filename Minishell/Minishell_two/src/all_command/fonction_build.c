/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** fonction_build
*/


#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "struct.h"
#include "proto_lib.h"

static int parameter_after_command(base_minishell_t *base, need_tab_t *need_tab)
{
    if (need_tab->fd_pos + 1 > need_tab->tab_len){
        if (my_strncmp("|", base->p_command[need_tab->tab_pos_y]
        [need_tab->tab_pos_x + 1], 1) == OK)
            return OK;
        if (my_strncmp(">", base->p_command[need_tab->tab_pos_y]
        [need_tab->tab_pos_x + 1], 1) == OK)
            return OK;
        if (my_strncmp("<", base->p_command[need_tab->tab_pos_y]
        [need_tab->tab_pos_x + 1], 1) == OK)
            return OK;
        if (my_strncmp(">>", base->p_command[need_tab->tab_pos_y]
        [need_tab->tab_pos_x + 1], 2) == OK)
            return OK;
        if (my_strncmp("<<", base->p_command[need_tab->tab_pos_y]
        [need_tab->tab_pos_x + 1], 2) == OK)
            return OK;
    }
    return KO;
}

static int execution(base_minishell_t *base, char **tab, int n)
{
    if (n == 0){
        if (cd_reprogramming(base, tab) != OK)
                base->return_value = 1;
    }
    if (n == 1){
        if (unsetenv_exit(base, tab) != OK)
                base->return_value = 1;
    }
    if (n == 2){
        if (setenv_exit(base, tab) != OK)
                base->return_value = 1;
    }
}

static int fontion_build_ter(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command)
{
    if (my_strncmp("unsetenv", tab_command[0], 8) == OK){
        duplicate_fonction(base, need_tab);
        if (parameter_after_command(base, need_tab) == OK)
            return OK;
        else
            execution(base, tab_command, 1);
        return OK;
    }
    return KO;
}

static int fonction_build_sub(base_minishell_t *base, need_tab_t *need_tab,
char **tab_command)
{
    int len_tab = 0;
    if (my_strncmp("setenv", tab_command[0], 6) == OK){
        duplicate_fonction(base, need_tab);
        if (parameter_after_command(base, need_tab) == OK &&
        (len_tab = my_tablen(tab_command) > 1))
            return OK;
        else
            execution(base, tab_command, 2);
        return OK;
    }
    if (my_strncmp("env", tab_command[0], 3) == OK){
        if (print_env(base->env) != OK)
            base->return_value = 1;
        return OK;
    }
    return KO;
}

int fonction_build(base_minishell_t *base, need_tab_t *need_tab, int *exit,
char **tab_command)
{
    if (my_strncmp("exit", tab_command[0], 4) == OK){
        duplicate_fonction(base, need_tab);
        if (parameter_after_command(base, need_tab) == OK)
            return OK;
        *exit = 1;
        return OK;
    }
    if (my_strncmp("cd", tab_command[0], 3) == OK){
        duplicate_fonction(base, need_tab);
        if (parameter_after_command(base, need_tab) == OK)
            return OK;
        else
            execution(base, tab_command, 1);
        return OK;
    }
    if (fonction_build_sub(base, need_tab, tab_command) == OK)
        return OK;
    return KO;
}
