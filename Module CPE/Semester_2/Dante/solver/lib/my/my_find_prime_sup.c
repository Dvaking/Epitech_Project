/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** task07
*/

int my_is_prime2(int compte)
{
    int result = 0;
    for (int div = 2; div < compte; div = div + 1) {
        result = compte % div;
        if (result == 0){
            return (0);
        }
    }
    return (1);
}

int my_find_prime_sup(int nb)
{
    int prime_num = 0;
    int compte = nb;
    if (nb <= 2){
        return (2);
    }
    while (compte < 2147483646) {
        prime_num = my_is_prime2(compte);
        if (prime_num == 1){
            return (compte);
        }
        compte = compte + 1;
    }
    return ('a');
}
