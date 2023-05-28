/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-clara.ortu
** File description:
** print_padding
*/

#include <stdbool.h>
#include "my_proto.h"

int print_padding(int nb_pad, char c)
{
    for (int i = 0; i < nb_pad; i += 1)
        my_putchar(c);
    return (nb_pad);
}
