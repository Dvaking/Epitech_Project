/*
** EPITECH PROJECT, 2022
** str to int
** File description:
** convert an str to int
*/

int str_to_int(char *str)
{
    int i = 0;
    int j = 0;
    int nbr = 0;
    if (str[0] == '-') {
        i = 1;
    }
    while (str[i] != '\0') {
        nbr *= 10;
        nbr += str[i] - '0';
        i += 1;
        j += 1;
    }
    if (j != i)
        nbr *= -1;
    return nbr;
}
