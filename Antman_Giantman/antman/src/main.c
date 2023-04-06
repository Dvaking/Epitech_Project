/*
** EPITECH PROJECT, 2023
** main
** File description:
** main of antman
*/

#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "proto_lib.h"
#include "proto_antman.h"

static int antman(int ac, char **av)
{
    if (str_to_int(av[2]) == 1) {
        if (lyr_files(av[1]) == 1)
            return 84;
    }
    if (str_to_int(av[2]) == 2){
        if (html_files(av[1]) == 1)
            return 84;
    }
    if (str_to_int(av[2]) == 3) {
        if (ppm_files(av[1]) == false)
            return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int return_value = 0;
    if (argc != 3) {
        return 1;
    } else {
        return_value = antman(argc, argv);
    }

    return return_value;
}
