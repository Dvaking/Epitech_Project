/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** proto_giantman
*/

#ifndef PROTO_GIANTMAN_H_
    #define PROTO_GIANTMAN_H_
    #include <stdbool.h>
    #include <sys/stat.h>
    #include "linked_list.h"

        /*extention file/ */
    int lyr_file(char *filepath);
    bool uncompress_ppm(char *filepath);
    int html_file(char *filepath);

        /* decompress/ */
    int decompress_setence(list_t *list);

        /* all_string/ */
    int selected_setence(list_t *selectioned, int *key);
    char *str_create(list_t *list);
    int str_modif(list_t *move, char *str);

        /* error_handing/ */
    int error_file_buffer(struct stat s, int fd, char *buffer, char **av);
    int verification_pointer_decompress(list_t *move, list_t *comparison);


#endif /* !PROTO_GIANTMAN_H_ */
