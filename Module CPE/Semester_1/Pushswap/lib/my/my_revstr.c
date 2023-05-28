/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** reverse le mot et le return
*/

int taille(char const *str)
{
    int l = 0;
    while (str[l] != '\0') {
        l = l + 1;
    }
    return (l);
}

char *my_revstr(char *str)
{
    int last = taille(str);
    int f = 0;
    char charact = '\0';
    last = last - 1;
    while (f <= last / 2) {
        charact = str[f];
        str[f] = str[last -  f];
        str[last - f] = charact;
        f = f + 1;
    }
    return (str);
}
