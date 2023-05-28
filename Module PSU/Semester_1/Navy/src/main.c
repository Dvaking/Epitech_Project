/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "proto_lib.h"
#include "proto.h"

static int navy(int ac, char **av)
{
    all_player_t *all_player = malloc(sizeof(all_player_t));
    char **bin_tab = generate_tab();
    if (ac == 2){
        if (player_one(av, bin_tab, all_player) == 1)
            return 1;
    }
    if (ac == 3){
        if (player_two(av, bin_tab, all_player) == 1)
            return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc > 3 || argc < 2)
        return 84;
    if (argc == 2 && argv[1][0] == '-')
        help(argv);
    if (argc == 2){
        if (check_file(argv, 1) == 84)
            return 84;
    }
    if (argc == 3){
        if (check_file(argv, 2) == 84)
            return 84;
    }
    if (navy(argc, argv) == 1)
        return 1;
    return 0;
}
