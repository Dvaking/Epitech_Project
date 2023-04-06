/*
** EPITECH PROJECT, 2023
** ppm_files
** File description:
** compress the ppm files
*/

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "proto_giantman.h"
#include "proto_lib.h"

static char *init_head(void)
{
    char *head = malloc(sizeof(char) * 5);
    if (head == NULL)
        return NULL;
    head[0] = '2';
    head[1] = '5';
    head[2] = '5';
    head[3] = '\n';

    return head;
}

static bool print_uncompressed_ppm(char *str, long size, char **splited_line)
{
    int value = 0;
    int count_head = 0;
    int count_comp = 0;
    char *head = init_head();
    while (my_strncmp(splited_line[count_head], head, 4) == 0) {
        write(1, splited_line[count_head],
        my_strlen(splited_line[count_head]));
        count_head += 1;
        count_comp += my_strlen(splited_line[count_head]);
    }
    write(1, splited_line[count_head], my_strlen(splited_line[count_head]));
    count_comp += my_strlen(splited_line[count_head]);
    for (int i = count_comp; i != size; i += 1) {
        value = (__uint8_t)(str[i]);
        my_put_nbr(value);
        write(1, "\n", 1);
    }
    free(head);
    return true;
}

bool uncompress_ppm(char *filepath)
{
    char *str = load_file_in_mem(filepath);
    if (str == NULL || str[0] == '\0' || str[0] == '\n')
        return false;
    char **splited_line = split_my_str(str);
    if (splited_line == NULL)
        return false;
    for (int i = 0 pixels[i] != NULL; i += 1){
        my_printf("%s\n", pixels[i]);
    }
    free(str);
    free_array(splited_line);
    return true;
}


static int check_str(char *buffer)
{
    int count = 0;
    for (int i = 0; buffer[i] != '\0'; i += 1){
        if (buffer[i] >= '!' && buffer[i] == '~')
            count += 1;
    }
    if (count != 0)
        return 1;
    return 0;
}
