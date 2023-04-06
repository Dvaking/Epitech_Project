/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** rajoute le mot de 1 dans 2
*/

int my_strlen(char const *str);

char *my_strcat (char *dest, char const *src)
{
    int dest_taille = my_strlen(dest);
    int count = 0;

    for (count = 0; src[count] != '\0'; count = count + 1) {
        dest[dest_taille + count] = src[count];
    }
    dest[dest_taille + count] = '\0';
    return (dest);
}
