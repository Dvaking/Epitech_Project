/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** proto
*/

#ifndef PROTO_H_
    #define PROTO_H_
    #include "linked_list.h"

    list_t *add_node_end(list_t *list, char *lines);
    int count_nodes(list_t *list);
    list_t *create_list(char *lines);
    void free_list(list_t *head);
    int my_strlen(char const *str);
    void print_node(list_t *list);
    list_t *swap_first_nodes(list_t *list);
    list_t *my_word_array_to_list(list_t *list, char **word_array);
    void free_array(char **line_array);


#endif /* !PROTO_H_ */
