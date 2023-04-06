/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** free_tab
*/

#include <unistd.h>
#include <stdlib.h>

#include "struct.h"
#include "macro.h"

int free_tab(char **tab)
{
    if (tab == NULL)
        return KO;
    for (int i = 0; tab[i] != NULL; i += 1)
        free(tab[i]);
    free(tab);
    return OK;
}

int free_str(all_str_t *all_str)
{
    free(all_str->str);
    free(all_str);
}
