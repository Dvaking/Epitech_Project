/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** tab_hit_miss
*/

#include <signal.h>
#include <unistd.h>

#include "proto.h"
#include "proto_lib.h"

void modification_tab_check_hit_or_miss(char **tab, char *reception, int pid,
int *boat)
{
    if (check_player_tab(tab, reception) == 1){
        my_printf("%s: hit\n", reception);
        usleep(1000);
        kill(pid, SIGUSR2);
        modif_tab_hit_miss(tab, reception, 1);
        *boat -= 1;
    } else {
        my_printf("%s: missed\n", reception);
        usleep(1000);
        kill(pid, SIGUSR1);
        modif_tab_hit_miss(tab, reception, 0);
    }
}
