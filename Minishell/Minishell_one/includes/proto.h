/*
** EPITECH PROJECT, 2023
** proto.h
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_

    #include <stdlib.h>
    #include "struct.h"

    int minishell_one(int ac, char const *const *av, char **env);

        /* error_handing */
    int check_argc_argv(int ac, char const *const *av);

        /* all tab */
    char **take_env(char **env);
    char **reduce_tab(char **src, char *str);
    char **enlarge_tab(char **src, char *variable, char *value);
    char **add_array_to_tab(all_str_t *all_str, char **src, char *value,
    int len_src);
    char **modif_array_to_tab(all_str_t *all_str, char **src, char *value,
    int len_src);

        /* toolbox */
    char *take_in_env(char **env, char *str);
    char *copy_entry1(interaction_tab_t *all_tab);
    char *copy_entry2(interaction_tab_t *all_tab);
    int starting(void);
    int take_entry(interaction_tab_t *all_tab, char **env, int *restart);
    char **take_env(char **env);
    char **take_path(char **env, char *str);
    int free_tab(char **tab);
    int free_str(all_str_t *all_str);

        /* all_command */
    int command(interaction_tab_t *all_tab, char **env, int *return_echo);
    int check_command_and_execute(interaction_tab_t *all_tab, int *exit,
    int *return_echo);
    int print_env(char **env);
    int cd_reprogramming(interaction_tab_t *all_tab);
    int setenv_exit(interaction_tab_t *all_tab);
    int unsetenv_exit(interaction_tab_t *all_tab);
    int unsetenv_reprogramming(interaction_tab_t *all_tab, char *str);
    int setenv_reprogramming(interaction_tab_t *all_tab, char *variable,
    char *value);

        /* all_cd */
    int move_to_home(interaction_tab_t *all_tab);
    int move_from_home(interaction_tab_t *all_tab);
    int return_old_folder(interaction_tab_t *all_tab);
    int move_in_folder(interaction_tab_t *all_tab, char *direction);


#endif /* !PROTO_H_ */
