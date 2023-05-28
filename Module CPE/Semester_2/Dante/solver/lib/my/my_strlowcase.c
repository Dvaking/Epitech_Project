/*
** EPITECH PROJECT, 2022
** my_strlowcase
** File description:
** met tout en minuscule
*/

char *my_strlowcase(char *str)
{
    int count = 0;
    while (str[count] != '\0') {
        if (str[count] >= 'A' && str[count] <= 'Z') {
            str[count] = str[count] + 32;
        }
        count += 1;
    }
    return (str);
}
