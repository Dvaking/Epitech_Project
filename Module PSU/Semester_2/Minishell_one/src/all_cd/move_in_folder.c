/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** move_in_folder
*/

#include <unistd.h>

#include "proto.h"
#include "macro.h"
#include "struct.h"
#include "proto_lib.h"

static char *get_my_pwd(void)
{
    char *buffer = malloc(sizeof(char) * 4096);
    if (getcwd(buffer, 4095) == NULL)
        return NULL;
    return buffer;
}

int move_in_folder(interaction_tab_t *all_tab, char *direction)
{
    int len_direction = my_strlen(direction);
    char *old_pwd = get_my_pwd();
    if (old_pwd == NULL)
        return KO;
    if (chdir(direction) == -1){
        write(2, direction, len_direction);
        write(2, ": no such file or directory\n", 28);
        free(old_pwd);
        return KO;
    } else {
        char *pwd = get_my_pwd();
        setenv_reprogramming(all_tab, "PWD", pwd);
        setenv_reprogramming(all_tab, "OLDPWD", old_pwd);
        free(pwd);
    }
    free(old_pwd);
    return OK;
}

int return_old_folder(interaction_tab_t *all_tab)
{
    if (all_tab == NULL)
        return KO;
    char *last_pwd = take_in_env(all_tab->env, "OLDPWD=");
    char *my_pwd = get_my_pwd();
    if (last_pwd == NULL || my_pwd == NULL)
        return KO;
    int len_pwd = my_strlen(my_pwd);
    if (my_strncmp_for_cd(last_pwd, my_pwd, len_pwd) == OK)
        write(2, ": No such file or directory.\n", 29);
    if (move_in_folder(all_tab, last_pwd) != OK){
        free(my_pwd);
        free(last_pwd);
        return KO;
    }
    free(my_pwd);
    return OK;
}

int move_to_home(interaction_tab_t *all_tab)
{
    char *home = take_in_env(all_tab->env, "HOME=");
    if (home == NULL)
        return KO;
    if (move_in_folder(all_tab, home) != OK)
        free(home);
        return KO;
    free(home);
    return OK;
}

int move_from_home(interaction_tab_t *all_tab)
{
    if (all_tab->entry[1][1] == '\0'){
        if (move_to_home(all_tab) != OK)
            return KO;
    } else {
        char *home = take_in_env(all_tab->env, "HOME=");
        char *move_home = my_strcat(home, all_tab->entry[1]);
        if (move_in_folder(all_tab, move_home) != OK){
            free(move_home);
            return KO;
        }
        free(move_home);
    }
    return OK;
}
