/*
** EPITECH PROJECT, 2023
** Minishell1
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    typedef struct interaction_tab {
        char **path;
        char **entry;
        char **env;
    } interaction_tab_t;

    typedef struct all_str {
        char *str;
        int len_str;
    } all_str_t;

#endif /* !STRUCT_H_ */
