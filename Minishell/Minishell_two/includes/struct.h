/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

        typedef struct base_minishell {
        char **path;
        char **command;
        char ***p_command;
        char **env;
        int return_value;
        int yes_or_not;
        int exit;
    } base_minishell_t;

    typedef struct need_tab {
        int **fd;
        int fd_pos;
        int tab_pos_x;
        int tab_pos_y;
        int tab_len;
        int nbr_parameter;
        int redirect_arg;
        int aft_arg;
    } need_tab_t;
    typedef struct all_str {
        char **p_str;
        char *str;
        int len_str;
    } all_str_t;

#endif /* !STRUCT_H_ */
