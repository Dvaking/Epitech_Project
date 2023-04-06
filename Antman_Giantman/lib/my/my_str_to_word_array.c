/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** split an array in word array
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int my_strlen(char const *str);

int pass_no_alpha_num(char const *str, int begin)
{
    int count_char = 0;
    if (str[begin] == '\0')
        return 0;
    while ((str[begin] < 'a' || str[begin] > 'z') &&
        (str[begin] < 'A' || str[begin] > 'Z') &&
        (str[begin] < '0' || str[begin] > '9')) {
        count_char += 1;
        begin += 1;
    }
    return count_char;
}

int count_word_number(char const *str)
{
    int nbr_word = 0;
    if (str == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((str[i] < 'a' || str[i] > 'z') &&
        (str[i] < 'A' || str[i] > 'Z') &&
        (str[i] < '0' || str[i] > '9')) {
            i += pass_no_alpha_num(str, i);
            nbr_word += 1;
        }
    }
    if (nbr_word == 0 && my_strlen(str) != 0)
        return 1;
    if (str[0] == '\0')
        return 0;
    return nbr_word + 1;
}

int count_char(char const *str, int begin)
{
    int count_char = 0;
    if (str[begin] == '\0')
        return 0;
    while ((str[begin] >= 'a' && str[begin] <= 'z') ||
        (str[begin] >= 'A' && str[begin] <= 'Z') ||
        (str[begin] >= '0' && str[begin] <= '9')) {
        count_char += 1;
        begin += 1;
    }
    return count_char;
}

char *take_word_into_tab(char const *str, int i, int nbr_char,
int nbr_word)
{
    int end_word = i + nbr_char;
    int count = 0;
    char *str_word = malloc(sizeof(char) * (nbr_char + 1));
    str_word[nbr_char] = '\0';
    if (str_word == NULL)
        return NULL;
    if (nbr_word == -1)
        return NULL;
    while (i != end_word) {
        str_word[count] = str[i];
        i += 1;
        count += 1;
    }
    return str_word;
}

char **my_str_to_word_array(char const *str)
{
    int nbr_word = count_word_number(str);
    int nbr_char = 0;
    int j = 0;
    if (nbr_word == -1)
        return NULL;
    char **word_array = malloc(sizeof(char *) * (nbr_word + 1));
    if (word_array == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((nbr_char = count_char(str, i)) != 0) {
            word_array[j] = take_word_into_tab(str, i, nbr_char, nbr_word);
            j += 1;
            i += nbr_char;
        }
    }
    word_array[nbr_word] = NULL;
    return word_array;
}
