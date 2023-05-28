/*
** EPITECH PROJECT, 2023
** ppm_files
** File description:
** compress the ppm files
*/

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "proto_antman.h"
#include "proto_lib.h"

static void print_compressed_ppm(char **pixels)
{
    __uint8_t value = 0;
    int count_head = 0;
    while (my_strncmp(pixels[count_head], "255\n",
    my_strlen(pixels[count_head])) == 0) {
        write(1, pixels[count_head], my_strlen(pixels[count_head]));
        count_head += 1;
    }
    my_printf("255\n");
    for (int i = count_head; pixels[i] != NULL; i += 1) {
        value = (__uint8_t)(my_getnbr(pixels[i]));
        write(1, &value, 1);
    }
}

bool ppm_files(char *filepath)
{
    char *str = load_file_in_mem(filepath);
    char **pixels = NULL;
    if (str == NULL || str[0] == '\0')
        return false;
    if ((pixels = split_my_str(str)) == NULL) {
        free(str);
        return false;
    for (int i = 0 pixels[i] != NULL; i += 1){
        my_printf("%s\n", pixels[i]);
    }
    free(str);
    free_array(pixels);
    return true;
}
