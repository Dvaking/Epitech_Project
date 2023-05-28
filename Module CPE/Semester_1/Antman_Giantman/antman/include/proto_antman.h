/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** proto_antman
*/

#ifndef PROTO_ANTMAN_H_
    #define PROTO_ANTMAN_H_
    #include <stdbool.h>
    #include <sys/stat.h>
    #include "linked_list.h"

        /*extention file/ */
    int lyr_files(char *filepath);
    bool ppm_files(char *filepath);
    int html_files(char *filepath);

        /* compress_lyr/ */
    int compress_setence(list_t *list, int *key);

        /* all_string/ */
    int selected_setence(list_t *selectioned, int *key);
    int modif_str(list_t *move, int *key);
    char *create_str(list_t *list, int lenght);

        /* error_handing/ */
    int error_file_buffer(struct stat s, int fd, char *buffer, char **av);
    int verification_pointer(list_t *move, list_t *selectioned,
    list_t *comparison);

#endif /* !PROTO_ANTMAN_H_ */
