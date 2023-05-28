/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** player_two
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <struct.h>
#include <unistd.h>

#include "proto.h"
#include "proto_lib.h"

t_player *get_map_player2(char *filename, all_player_t *all_player)
{
    int i = 0;
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    file = fopen(filename, "r");
    while ((nread = getline(&line, &len, file)) != -1) {
        i += 1;
        create_struct_boat1(line, i, all_player->p2);
    }
    free(line);
    fclose(file);
    return (all_player->p2);
}

int player_two(char **av, char **binary_tab, all_player_t *all_player)
{
    all_player->p2 = malloc(sizeof(t_player));
    all_player->p2 = get_map_player2(av[2], all_player);
    char **my_tab = generation_map(all_player->p2, 1);
    char **enemy_tab = generation_map(all_player->p2, 0);
    int pid_enemy = char_to_int(av[1]);
    connection_player2(pid_enemy);
    if (display_player2(binary_tab, my_tab, enemy_tab, pid_enemy) == 1)
        return 1;
    return 0;
}
