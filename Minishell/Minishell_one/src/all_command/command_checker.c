/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** command_checker
*/

#include <unistd.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static int check_reprograming_command_sub(interaction_tab_t *all_tab,
int *reprograming_command)
{
    if (my_strncmp("unsetenv", all_tab->entry[0], 3) == OK){
        if (unsetenv_exit(all_tab) != OK)
            return KO;
        *reprograming_command = 1;
        return OK;
    }
    if (my_strncmp("setenv", all_tab->entry[0], 3) == OK){
        if (setenv_exit(all_tab) != OK)
            return KO;
        *reprograming_command = 1;
        return OK;
    }
    if (my_strncmp("cd", all_tab->entry[0], 3) == OK){
        if (cd_reprogramming(all_tab) != OK)
            return KO;
        *reprograming_command = 1;
        return OK;
    }
    return OK;
}

static int check_reprograming_command(interaction_tab_t *all_tab, int *exit,
int *reprograming_command)
{
    if (my_strncmp("exit", all_tab->entry[0], 4) == OK && all_tab->entry[0][4]
    == '\0'){
        *reprograming_command = 1;
        *exit = 1;
        return OK;
    }
    if (my_strncmp("env", all_tab->entry[0], 3) == OK){
        if (print_env(all_tab->env) != OK)
            return KO;
        *reprograming_command = 1;
        return OK;
    }
    if (check_reprograming_command_sub(all_tab, reprograming_command) != OK)
        return KO;
    return OK;
}

int check_command_and_execute(interaction_tab_t *all_tab, int *exit,
int *return_echo)
{
    int reprograming_command = 0;
    if (all_tab == NULL)
        return KO;
    if (check_reprograming_command(all_tab, exit, &reprograming_command) != 0)
        return KO;
    if (reprograming_command != 0)
        return OK;
    if (command(all_tab, all_tab->env, return_echo) != 0)
        return KO;
    return OK;
}
