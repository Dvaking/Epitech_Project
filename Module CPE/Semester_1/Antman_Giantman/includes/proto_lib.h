/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** proto_lib
*/


#ifndef LIB_H_
    #define LIB_H_

    #include "linked_list.h"
    #include <stdbool.h>

        /* libmy/ */
    char **split_my_str(char const *str);
    char **my_str_to_word_array(char const *str);
    bool is_alpha_num(char ch);
    bool my_str_isnum(char const *str);
    int my_str_isalpha(char const *str);
    int my_strncmp(char const *s1, char const *s2, int n);
    int my_strlen(char const *str);
    int my_getnbr(char const *str);
    int str_to_int(char *str);
    char **str_to_tab(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    int my_put_nbr(int nb);

        /*my_printf/*/
    int my_printf(char const *format, ...);

        /*linked_list/*/
    list_t *add_node_end(list_t *list, char *lines);
    int count_nodes(list_t *list);
    list_t *create_list(char *lines);
    void free_list(list_t *head);
    int my_strlen(char const *str);
    void print_node(list_t *list);
    list_t *swap_first_nodes(list_t *list);
    list_t *my_word_array_to_list(list_t *list, char **word_array);
    void free_array(char **line_array);
    char *load_file_in_mem(char *filepath);


#endif /* !LIB_H_ */
