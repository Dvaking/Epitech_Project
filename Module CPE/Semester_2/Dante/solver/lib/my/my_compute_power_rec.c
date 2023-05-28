/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** task04
*/

int protection(int p, int nb)
{
    if (p == 0){
        return (1);
    }
    if (p < 0) {
        return (0);
    }
}

int my_compute_power_rec(int nb, int p)
{
    long int i = nb;
    int result;
    if (protection(p, nb) == 0) {
        return (0);
    }
    if (p == 1){
        return (nb);
    }
    i = nb * my_compute_power_rec(nb, p - 1);
    if (i > 2147483647 || i < -2147483648){
        return (0);
    }
    result = (int)i;
    return (result);
}
