/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-navy-marc.mendia
** File description:
** take_entry
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

char *take_entry(void)
{
    write(1, "\nattack: ", 9);
    char *entry;
    size_t len = 0;
    ssize_t nread;
    nread = getline(&entry, &len, stdin);
    if ((entry[0] < 'A' || entry[0] > 'H') || (entry[1] < '1' || entry[1] > '8')
    || nread != 3){
        write(1, "wrong position\n", 15);
        return take_entry();
    }
    entry[2] = '\0';
    return entry;
}
