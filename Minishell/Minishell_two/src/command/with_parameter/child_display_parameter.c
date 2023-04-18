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

int child_display_parameter(base_minishell_t *base, need_tab_t *need_tab)
{
    char **tab_command = NULL;
    if (base == NULL || need_tab == NULL)
        return KO;
    tab_command = my_splitstr(base->p_command[need_tab->tab_pos_y]
    [need_tab->tab_pos_x], ' ');
    if (check_fontion_build(base, need_tab, tab_command) == OK)
        return OK;
    if (command(base, need_tab, tab_command) != OK)
        return KO;
    free_tab_char(tab_command);
    return OK;
}
