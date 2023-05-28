/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** env
*/

#include <unistd.h>

#include "macro.h"
#include "proto.h"
#include "proto_lib.h"

int print_env(char **env)
{
    if (env == NULL)
        return KO;
    int len = 0;
    for (int y = 0; env[y] != NULL; y += 1){
        len = my_strlen(env[y]);
        if (len == KO)
            return KO;
        if (write(1, env[y], len) == KO)
            return KO;
        if (write(1, "\n", 1) == KO)
            return KO;
    }
    return OK;
}

int unsetenv_exit(interaction_tab_t *all_tab)
{
    if (all_tab == NULL)
        return KO;
    int i = 0;
    for (i = 0; all_tab->entry[i] != NULL; i += 1);
    if (i == 1){
        write(1, "unsetenv: Too few arguments.\n", 29);
        return 0;
    }
    for (int y = 1; all_tab->entry[y] != NULL; y += 1){
        if (unsetenv_reprogramming(all_tab, all_tab->entry[y]) != OK)
            return OK;
    }
    return OK;
}

int setenv_exit(interaction_tab_t *all_tab)
{
    if (all_tab == NULL)
        return KO;
    int i = 0;
    for (i = 0; all_tab->entry[i] != NULL; i += 1);
    if (i == 1){
        print_env(all_tab->env);
        return 0;
    } else if (i > 3) {
        write(2, "setenv: Too many arguments.\n", 29);
        return 1;
    }
    if (my_all_str_isalpha_num(all_tab->entry[1]) != OK){
        write(2, "setenv: Variable name must contain alphanumeric characters.\n"
        , 60);
        return 1;
    }
    if (setenv_reprogramming(all_tab, all_tab->entry[1], all_tab->entry[2])
    != OK)
        return OK;
    return OK;
}
