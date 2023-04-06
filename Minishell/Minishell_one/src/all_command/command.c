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


static char *string_command(char *path, char *entry)
{
    int y = 0;
    int len = (my_strlen(path) + my_strlen(entry) + 1);
    if (len == KO)
        return NULL;
    char *command = malloc(sizeof(char) * (len + 1));
    if (command == NULL)
        return NULL;
    for (int b = 0; b < my_strlen(path); y += 1) {
            command[y] = path[b];
            b += 1;
    }
    command[y] = '/';
    y += 1;
    for (int b = 0; b < my_strlen(entry); y += 1){
            command[y] = entry[b];
            b += 1;
    }
    command[len] = '\0';
    return command;
}

static int command_execute(interaction_tab_t *all_tab, char **env)
{
    if (all_tab == NULL || env == NULL)
        return KO;
    execve(all_tab->entry[0], all_tab->entry, env);
    if (all_tab->entry[0][0] != '.' && all_tab->entry[0][1] != '/'){
        for (int i = 0; all_tab->path[i] != NULL; i += 1){
            char *command = string_command(all_tab->path[i],
            all_tab->entry[0]);
            execve(command, all_tab->entry, env);
            free(command);
        }
    }
    write(1, all_tab->entry[0], my_strlen(all_tab->entry[0]));
    write(1, ": Command not found.\n", 21);
    free_tab(all_tab->entry);
    free_tab(all_tab->env);
    free_tab(all_tab->path);
    exit(1);
}

static void child_display_sub(int *return_echo, int return_value, int segfault,
int core_dump_or_not)
{
    if (core_dump_or_not == 128){
        *return_echo += 128;
        write(2, " (core dumped)", 14);
    }
    if (return_value == 1)
        *return_echo += 1;
    if (segfault == 8 || segfault == 11){
        write(1, "\n", 1);
    }
}

static int child_display(pid_t pid, int *return_echo, int value)
{
    waitpid(pid, &value, 0);
    int return_value = WEXITSTATUS(value);
    int core_dump_or_not = WCOREDUMP(value);
    int segfault = WTERMSIG(value);
    if (segfault == 8){
        *return_echo += 8;
        write(2, "Floating execption", 18);
    }
    if (segfault == 11){
        *return_echo += 11;
        write(2, "Segmentation fault", 18);
    }
    child_display_sub(return_echo, return_value, segfault, core_dump_or_not);
    return OK;
}

int command(interaction_tab_t *all_tab, char **env, int *return_echo)
{
    if (all_tab == NULL || env == NULL)
        return KO;
    pid_t pid = fork();
    if (pid < 0)
        return KO;
    if (pid == 0){
        int other_return = command_execute(all_tab, env);
        return other_return;
    } else {
        int value = 0;
        child_display(pid, return_echo, value);
        return OK;
    }
    return OK;
}
