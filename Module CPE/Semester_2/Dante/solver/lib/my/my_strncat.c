/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** fait la mm mais avec nb
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    char dest_taille = my_strlen(dest);
    int count = 0;
    for (count = 0; src[count] != '\0'; count = count + 1) {
        dest[dest_taille + count] = src[count];
        if (count >= nb) {
            dest[dest_taille + count] = '\0';
        }
    }
    while (count <= nb) {
        if (count == nb) {
            dest[dest_taille + count] = '\0';
        }
        count = count + 1;
    }
    return (dest);
}
