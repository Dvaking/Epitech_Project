/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** connection
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "proto_lib.h"
#include "struct.h"

variable_global_t variable_global = {0};

static void handler_player1_connection(int num, siginfo_t *info, void *nothing)
{
    variable_global.pid_player2 = info->si_pid;
    kill(variable_global.pid_player2, SIGUSR1);
}

static void handler_player2_connection(int num, siginfo_t *info, void *nothing)
{
    write(1,"successfuly connected\n", 23);
}

int connection_player1(void)
{
    struct sigaction player1;
    if (sigaction(SIGUSR2, NULL, &player1) != 0)
        return 1;
    player1.sa_flags |= SA_SIGINFO;
    player1.sa_sigaction = &handler_player1_connection;
    if (sigaction(SIGUSR2, &player1 , NULL) != 0)
        return 1;
    pause();
    write(1,"\nenemy connected\n", 18);
    return 0;
}

int connection_player2(int pid_enemy)
{
    my_printf("my pid: %d\n", getpid());
    kill(pid_enemy, SIGUSR2);
    struct sigaction player2;
    if (sigaction(SIGUSR1, NULL, &player2) != 0)
        return 1;
    player2.sa_flags |= SA_SIGINFO;
    player2.sa_sigaction = &handler_player2_connection;
    if (sigaction(SIGUSR1, &player2 , NULL) != 0)
        return 1;
    pause();
    return 0;
}
