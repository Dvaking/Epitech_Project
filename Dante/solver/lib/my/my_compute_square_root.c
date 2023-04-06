/*
** EPITECH PROJECT, 2022
** my_compute_squarre
** File description:
** verifie si c'est un nombre entier
*/

int my_compute_square_root(int nb)
{
    int whole_numb = 0;
    int result = 0;

    while (result < nb) {
        whole_numb = whole_numb + 1;
        result = whole_numb * whole_numb;
        if (result == nb) {
            return (whole_numb);
        }
    }
    return (0);
}
