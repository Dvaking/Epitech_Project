/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** command_with_pipe
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static int command_execute(base_minishell_t *base, need_tab_t *need_tab,
int *return_exit, char **tab_command)
{
    if (base == NULL || need_tab == NULL || tab_command == NULL)
        return KO;
    if (fonction_build(base, need_tab, return_exit, tab_command) == OK)
        return 0;
    else
        command(base, need_tab, tab_command);
    return 0;
}

int child_display_parameter(base_minishell_t *base, need_tab_t *need_tab,
int *exit)
{
    char **tab_command = NULL;
    if (base == NULL || need_tab == NULL)
        return KO;
    tab_command = my_splitstr(base->p_command[need_tab->tab_pos_y]
    [need_tab->tab_pos_x], ' ');
    if (command_execute(base, need_tab, exit, tab_command) != OK)
        return KO;
    free_tab_char(tab_command);
    return OK;
}
