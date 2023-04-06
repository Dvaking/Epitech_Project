/*
** EPITECH PROJECT, 2023
** linked list
** File description:
** linked list that stock all the data
*/

#ifndef LIST_S
    #define LIST_S

    typedef struct list_s {
        char *text;
        struct list_s *next;
        struct list_s *previous;
    }list_t;

#endif /* !LIST_S */
