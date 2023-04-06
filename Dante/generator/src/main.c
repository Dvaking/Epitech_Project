/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "proto_generator.h"

int main(int argc, char const *const *argv)
{
    if (check_argc_argv(argc, argv) != 0)
        return 84;
    return generator(argc, argv);
}
