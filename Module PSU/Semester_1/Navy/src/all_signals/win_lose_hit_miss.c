/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** handler_win_lose
*/

#include <signal.h>
#include <unistd.h>

#include "struct.h"
#include "proto.h"

extern variable_global_t variable_global;

static void handler_hit_or_miss(int num, siginfo_t *info, void *nothing)
{
    if (num == SIGUSR1){
        write(1, ": missed\n\n", 10);
        variable_global.hit_or_not = 0;
    }
    if (num == SIGUSR2){
        write(1, ": hit\n\n", 7);
        variable_global.hit_or_not = 1;
    }
}

void *hit_or_not(char **tab_neutral,  char *entry)
{
    int i = 0;
    struct sigaction player;
    write(1, entry, 3);
    if (sigaction(SIGUSR2, NULL, &player) != 0)
        return NULL;
    player.sa_sigaction = &handler_hit_or_miss;
    if (sigaction(SIGUSR2, &player, NULL) != 0)
        return NULL;
    if (sigaction(SIGUSR1, NULL, &player) != 0)
        return NULL;
    player.sa_sigaction = &handler_hit_or_miss;
    if (sigaction(SIGUSR1, &player, NULL) != 0)
        return NULL;
    while (i != 1){
        pause();
        modif_tab_hit_miss(tab_neutral, entry, variable_global.hit_or_not);
        i = 1;
    }
}

static void handler_win_or_loose(int num, siginfo_t *info, void *nothing)
{
    if (num == SIGUSR1){
        variable_global.win_or_not = 0;
    }
    if (num == SIGUSR2){
        variable_global.win_or_not = 1;
    }
}

int check_win(void)
{
    int i = 0;
    struct sigaction win_or_loose;
    if (sigaction(SIGUSR2, NULL, &win_or_loose) != 0)
        return 0;
    win_or_loose.sa_sigaction = &handler_win_or_loose;
    if (sigaction(SIGUSR2, &win_or_loose, NULL) != 0)
        return 0;
    if (sigaction(SIGUSR1, NULL, &win_or_loose) != 0)
        return 0;
    win_or_loose.sa_sigaction = &handler_win_or_loose;
    if (sigaction(SIGUSR1, &win_or_loose, NULL) != 0)
        return 0;
    while (i != 1){
        pause();
        if (variable_global.win_or_not == 1)
            return 1;
        i = 1;
    }
    return 0;
}

int check_loose(int boat, int pid)
{
    if (boat == 0){
        usleep(1000);
        kill(pid, SIGUSR2);
        return 1;
    } else {
        usleep(1000);
        kill(pid, SIGUSR1);
        return 0;
    }
}
