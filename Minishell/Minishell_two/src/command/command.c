/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** execute_command
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


static void wait_fonction(base_minishell_t *base, need_tab_t *need_tab,
pid_t pid, int value)
{
    if (need_tab->tab_len < 1 || need_tab->tab_len == need_tab->tab_pos_x)
        waitpid(pid, &value, WUNTRACED);
    else
        waitpid(pid, &value, WUNTRACED | WNOHANG);
}

static int command_execute(base_minishell_t *base, need_tab_t *need_tab,
char **tab)
{
    if (base == NULL || need_tab == NULL)
        return KO;
    duplicate_fonction(base, need_tab);
    if (base->yes_or_not == 1){
        if (fonction_build(base, need_tab, tab) == OK){
            free_all(base, need_tab);
            exit(0);
        }
    }
    execve(tab[0], tab, base->env);
    if (tab[0][0] != '.' && tab[0][1] != '/'){
        for (int i = 0; base->path[i] != NULL; i += 1){
            char *command = string_command(base->path[i], tab[0]);
            execve(command, tab, base->env);
            free(command);
        }
    }
    write(2, tab[0], my_strlen(tab[0]));
    write(2, ": Command not found.\n", 21);
    free_all(base, need_tab);
    exit(1);
}

static void child_display_sub(base_minishell_t *base, int return_value,
int segfault, int core_dump_or_not)
{
    if (core_dump_or_not == 128){
        base->return_value += 128;
        write(2, " (core dumped)", 14);
    }
    if (return_value == 1)
        base->return_value += 1;
    if (segfault == 8 || segfault == 11){
        write(1, "\n", 1);
    }
}

static int child_display(base_minishell_t *base, need_tab_t *need_tab,
pid_t pid, int value)
{
    close_fonction(base, need_tab);
    wait_fonction(base, need_tab, pid, value);
    int return_value = WEXITSTATUS(value);
    int core_dump_or_not = WCOREDUMP(value);
    int segfault = WTERMSIG(value);
    if (segfault == 8){
        base->return_value += 8;
        write(2, "Floating execption", 18);
    }
    if (segfault == 11){
        base->return_value += 11;
        write(2, "Segmentation fault", 18);
    }
    child_display_sub(base, return_value, segfault, core_dump_or_not);
    return OK;
}

int command(base_minishell_t *base, need_tab_t *need_tab, char **tab)
{
    if (base == NULL || need_tab == NULL)
        return KO;
    pid_t pid = fork();
    if (pid < 0)
        return KO;
    if (pid == 0){
        int other_return = command_execute(base, need_tab, tab);
        return other_return;
    } else {
        int value = 0;
        child_display(base, need_tab ,pid, value);
        return OK;
    }
    return OK;
}
