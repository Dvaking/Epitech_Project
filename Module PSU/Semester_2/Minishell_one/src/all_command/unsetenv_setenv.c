/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** unsetenv
*/

#include <unistd.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

int unsetenv_reprogramming(interaction_tab_t *all_tab, char *str)
{
    if (all_tab == NULL || str == NULL)
        return KO;
    char **dest = reduce_tab(all_tab->env, str);
    free_tab(all_tab->env);
    all_tab->env = take_env(dest);
    if (all_tab->env == NULL)
        return KO;
    free_tab(dest);
    return OK;
}

int setenv_reprogramming(interaction_tab_t *all_tab, char *variable,
char *value)
{
    if (all_tab == NULL || variable == NULL)
        return KO;
    char **dest = enlarge_tab(all_tab->env, variable, value);
    if (dest == NULL)
        return KO;
    free_tab(all_tab->env);
    all_tab->env = take_env(dest);
    if (all_tab->env == NULL)
        return KO;
    free_tab(dest);
    return OK;
}
