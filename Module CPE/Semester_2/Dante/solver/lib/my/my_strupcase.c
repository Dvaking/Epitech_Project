/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** met tout en majuscule
*/

char *my_strupcase(char *str)
{
    int count = 0;
    while (str[count] != '\0') {
        if (str[count] >= 'a' && str[count] <= 'z') {
            str[count] = str[count] - 32;
        }
        count += 1;
    }
    return (str);
}
