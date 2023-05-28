/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** player_one
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "proto.h"
#include "struct.h"
#include "proto_lib.h"

extern variable_global_t variable_global;

t_player *get_map_player1(char *filename, all_player_t *all_player)
{
    int i = 0;
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    file = fopen(filename, "r");
    while ((nread = getline(&line, &len, file)) != -1) {
        i += 1;
        create_struct_boat1(line, i, all_player->p1);
    }
    free(line);
    fclose(file);
    return (all_player->p1);
}

int player_one(char **av, char **binary_tab, all_player_t *all_player)
{
    all_player->p1 = malloc(sizeof(t_player));
    all_player->p1 = get_map_player1(av[1], all_player);
    char **my_tab = generation_map(all_player->p1, 1);
    char **enemy_tab = generation_map(all_player->p1, 0);
    if (check_line(all_player->p1) == 84 || check_collision(my_tab) != 50)
        return 1;
    my_printf("my_pid: %d\nwaiting for enemy connection...\n", getpid());
    connection_player1();
    if (display_player1(binary_tab, my_tab, enemy_tab) == 1)
        return 1;
    return 0;
}
