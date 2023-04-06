/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** minishell_one
*/

#include <unistd.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static int minishell_one_sub(interaction_tab_t *all_tab, char **env)
{
    if (all_tab == NULL || env == NULL)
        return 1;
    int exit = 0;
    int echo_or_not = 0;
    int return_echo = 0;
    int restart = 0;
    while (exit != 1){
        if ((echo_or_not = starting()) == -1)
            return 1;
        if (take_entry(all_tab, env, &restart) != OK)
            break;
        if (restart == 1)
            continue;
        if (check_command_and_execute(all_tab, &exit, &return_echo) != 0)
            return 1;
        free_tab(all_tab->entry);
    }
    return return_echo;
}

int minishell_one(int ac, char const *const *av, char **env)
{
    interaction_tab_t *all_tab = malloc(sizeof(interaction_tab_t));
    if (all_tab == NULL || env == NULL)
        return 1;
    int return_value = 0;
    all_tab->path = take_path(env, "PATH=");
    all_tab->env = take_env(env);
    if (all_tab->path == NULL)
        return 1;
    return_value = minishell_one_sub(all_tab, env);
    free_tab(all_tab->path);
    free_tab(all_tab->env);
    free(all_tab);
    return return_value;
}
