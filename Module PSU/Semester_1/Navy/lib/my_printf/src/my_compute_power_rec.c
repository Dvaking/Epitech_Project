/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** A recursive function that returns the first argument raised to the power p,
** where p is the second argument
*/

int     my_compute_power_rec(int nb, int p)
{
    int result;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}
