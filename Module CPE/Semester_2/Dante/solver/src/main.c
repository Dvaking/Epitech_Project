/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "proto.h"

int main(int argc, char const * const * argv)
{
    if (argc != 2)
        return 84;
    return solver(argv[1]);
}
