/*
** EPITECH PROJECT, 2022
** my_str_is_num
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    int count = 0;

    if (str[0] == '\0') {
        return (0);
    }
    while (str[count] != '\0') {
        if ((str[count] < '0' || str[count] > '9') && (str[count] != ' ')) {
            return (0);
        }
        count = count + 1;
    }
    return (1);
}
