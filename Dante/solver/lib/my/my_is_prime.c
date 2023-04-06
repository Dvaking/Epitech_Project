/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** task06
*/

int my_is_prime(int nb)
{
    int result = 0;
    if (nb < 2) {
        return (0);
    }
    if (nb == 2){
        return (1);
    }
    for (int div = 2; div < nb ; div = div + 1) {
        result = nb % div;
        if (result == 0) {
            return (0);
        }
    }
    return (1);
}
