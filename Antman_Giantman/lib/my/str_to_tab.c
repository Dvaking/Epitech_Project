/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-antman-marc.mendia
** File description:
** str_to_tab
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_strlen(char const *str);

static int count_line_number(char const *str)
{
    int nbr_line = -1;
    if (str == NULL)
        return nbr_line;
    for (int i = 0; str[i] != '\0' || str[i] != '\n'; i += 1) {
        if (str[i] == ' ')
            nbr_line += 1;
    }
    if (nbr_line == 0 && my_strlen(str) != 0)
        return 1;
    if (str[0] == '\0')
        return 0;
    if (str[my_strlen(str) - 1] != '\n')
        return nbr_line + 2;
    return nbr_line + 1;
}

static int count_char(char const *str, int begin)
{
    int count_char = 0;
    if (str[begin] == '\0')
        return 0;
    while (str[begin] != ' ') {
        if (str[begin] == '\0' || str[begin] == '\0')
            return count_char;
        count_char += 1;
        begin += 1;
    }
    return count_char + 1;
}

static char *take_line_into_tab(char const *str, int i, int nbr_char,
int nbr_line)
{
    int end_line = i + nbr_char;
    int count = 0;
    char *str_line = malloc(sizeof(char) * (nbr_char + 1));
    if (str_line == NULL)
        return NULL;
    str_line[nbr_char] = '\0';
    if (nbr_line == -1)
        return NULL;
    while (i != end_line) {
        str_line[count] = str[i];
        i += 1;
        count += 1;
    }
    return str_line;
}

char **str_to_tab(char const *str)
{
    int nbr_line = count_line_number(str);
    int nbr_char = 0;
    int j = 0;
    if (nbr_line == -1)
        return NULL;
    char **line_array = malloc(sizeof(char *) * (nbr_line + 1));
    if (line_array == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((nbr_char = count_char(str, i)) != 0) {
            line_array[j] = take_line_into_tab(str, i, nbr_char, nbr_line);
            j += 1;
            i += nbr_char - 1;
        }
    }
    line_array[nbr_line] = NULL;
    return line_array;
}
