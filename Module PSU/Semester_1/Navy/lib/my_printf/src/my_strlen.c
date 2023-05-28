/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Count and return the number of characters
** found in the string passed as parameter
*/

int     my_strlen(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0'){
        count += 1;
        i += 1;
    }
    return (count);
}
