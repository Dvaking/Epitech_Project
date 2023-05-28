/*
** EPITECH PROJECT, 2022
** protection
** File description:
** protection
*/

static int verif(char **av, int i)
{
    for (int b = 0; av[i][b] != '\0'; b += 1){
        if (av[i][b] < '0' && av[i][b] != '-' || av[i][b] > '9' && \
av[i][b] != '-'){
            return 84;
        }
    }
    return 0;
}

int protection_num(int ac, char **av)
{
    for (int i = 1; i < ac; i += 1){
        if (verif(av, i) == 84)
            return 84;
    }
    return 0;
}
