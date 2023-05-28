/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** get_signal
*/

#include <stddef.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "struct.h"

extern variable_global_t variable_global;

static void handler(int num, siginfo_t *info, void *nothing)
{
    if (num == SIGUSR1)
        variable_global.I = 0;
    if (num == SIGUSR2)
        variable_global.I = 1;
}

char *get_signal(char **binary_tab)
{
    int count = 0;
    char *str = malloc(sizeof(char) * 7);
    struct sigaction player;
    if (sigaction(SIGUSR2, NULL, &player) != 0)
        return NULL;
    player.sa_sigaction = &handler;
    if (sigaction(SIGUSR2, &player, NULL) != 0)
        return NULL;
    if (sigaction(SIGUSR1, NULL, &player) != 0)
        return NULL;
    player.sa_sigaction = &handler;
    if (sigaction(SIGUSR1, &player, NULL) != 0)
        return NULL;
    while (count != 6){
        pause();
        str[count] = (variable_global.I + '0');
        count += 1;
    }
    return str;
}
