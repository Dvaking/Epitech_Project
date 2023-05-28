/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** copie un mot dans un autre char sauf que si dest est plus grand
** alors on ajoute '\0' et n** on si dest < src
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int count = 0;
    while (count < n && src[count] != '\0') {
        dest[count] = src[count];
        count = count + 1;
    }
    if (count >= n){
        while (dest[count] != '\0') {
            dest[count] = '\0';
        }
    }
    return (dest);
}
