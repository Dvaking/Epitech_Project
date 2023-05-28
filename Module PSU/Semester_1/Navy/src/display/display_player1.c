/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** display_player1
*/

#include <stdbool.h>
#include <unistd.h>

#include "proto.h"
#include "struct.h"
#include "proto_lib.h"

extern variable_global_t variable_global;

int display_player1(char **binary_tab, char **tab, char **tab_neutral)
{
    int boat = 14;
    int pid = variable_global.pid_player2;
    while (true){
        display_all(tab, tab_neutral);
        char *entry = take_entry();
        send_signal(binary_tab, entry, pid);
        hit_or_not(tab_neutral, entry);
        if (check_win() == 1)
            return 0;
        write(1, "\nwaiting for enemy's attack...\n", 31);
        char *reception = get_signal(binary_tab);
        reception = signal_to_char(reception, binary_tab);
        modification_tab_check_hit_or_miss(tab, reception, pid, &boat);
        if (check_loose(boat, pid) == 1)
            return 1;
    }
}
