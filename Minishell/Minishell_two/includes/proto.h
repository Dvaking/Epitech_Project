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
    #include "struct_args_for_entry.h"

    int minishell_one(int ac, char const *const *av, char **env);

        /* error_handing */
    int check_argc_argv(int ac, char const *const *av);
    int error_message(int prev_args, int aft_args);
    int error_message_redirector(args_s_t *args);
    int check_redirector_input(all_str_t *all_str, int *x);
    int check_pipe(all_str_t *all_str, int *x);
    void error_and_free_message_cmd(base_minishell_t *base, char **tab);

        /* all tab */
    char **take_env(char **env);
    char **reduce_tab(char **src, char *str);
    char **enlarge_tab(char **src, char *variable, char *value);
    char **add_array_to_tab(all_str_t *all_str, char **src, char *value,
    int len_src);
    char **modif_array_to_tab(all_str_t *all_str, char **src, char *value,
    int len_src);
    int entry_w_parameter_or_not(base_minishell_t *base, char *entry,
    int *nbr_parameter);
    char **remove_of_tab(char **src, char *str);

        /* toolbox */
    char *take_in_env(char **env, char *str);
    char *copy_entry1(base_minishell_t *base);
    char *copy_entry2(base_minishell_t *base);
    int check_if_redirector(char *str, need_tab_t *need_tab);
    int starting(void);
    int take_entry(base_minishell_t *base, char **env, int *restart,
    int *count_parameter);
    char **take_env(char **env);
    int check_parameter_and_modif_tab(base_minishell_t *base);
    char **take_path(char **env, char *str);
    int free_all(base_minishell_t *base, need_tab_t *need_tab);
    int free_tab_char(char **tab);
    int free_big_tab(char ***tab);
    int free_tab_int(int **tab);
    int free_str(all_str_t *all_str);
    char **my_complexspliter(char const *str, char *separator,
    int nbr_parameter);
    int count_parameter(char *str);
    int count_parameter_sub(char **tab);
    void free_in_child(base_minishell_t *base, need_tab_t *need_tab,
    char **tab);

    int take_parameter(char *str);

        /* all_command */
    int command(base_minishell_t *base, need_tab_t *need_tab, char **tab);
    char *string_command(char *path, char *entry);
    int command_with_parameter(base_minishell_t *base, need_tab_t *need_tab,
    int *exit);
    int command_with_pipe(base_minishell_t *base, int *y);
    int check_command_and_execute(base_minishell_t *base, need_tab_t *need_tab,
    int *exit);
    int print_env(char **env);
    int cd_reprogramming(base_minishell_t *base, char **tab);
    int fonction_build(base_minishell_t *base, need_tab_t *need_tab, int *exit,
    char **tab);
    int fonction_cmd(base_minishell_t *base, need_tab_t *need_tab);
    int child_display_parameter(base_minishell_t *base, need_tab_t *need_tab,
    int *exit);
    int setenv_exit(base_minishell_t *base, char **tab);
    int unsetenv_exit(base_minishell_t *base, char **tab);
    int unsetenv_reprogramming(base_minishell_t *base, char *str);
    int setenv_reprogramming(base_minishell_t *base, char *variable,
    char *value);
    int duplicate_fonction(base_minishell_t *base, need_tab_t *need_tab);
    int count_pip(base_minishell_t *base, int *y);
    void close_fonction(base_minishell_t *base_minishell, need_tab_t *need_tab);
    char *string_command(char *path, char *entry);

        /* all_cd */
    int move_to_home(base_minishell_t *base);
    int move_from_home(base_minishell_t *base, char **tab);
    int return_old_folder(base_minishell_t *base);
    int move_in_folder(base_minishell_t *base, char *direction);


#endif /* !PROTO_H_ */
