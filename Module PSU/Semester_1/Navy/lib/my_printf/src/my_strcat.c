/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** function that concatenates two strings (day 07)
*/
int     my_strlen(char const *str);

char * my_strcat (char * dest , char const * src)

{
    int i = 0;
    int dest_l = my_strlen(dest);

    while (src[i] != '\0'){
        dest[dest_l + i] = src[i];
        i = i + 1;
    }

    dest[dest_l + i] = '\0';

    return (dest);
}
