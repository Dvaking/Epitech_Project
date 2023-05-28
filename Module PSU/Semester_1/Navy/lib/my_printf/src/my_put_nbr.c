/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** Display an integer given as parameter
*/

void my_putchar(char c);

static void print_pos(int nb)
{
    if (nb >= 10){
        print_pos(nb / 10);
    }
    my_putchar((nb % 10) + '0');
}

static void print_neg(int nb)
{
    if (nb <= -10){
        print_neg(nb / 10);
    }
    my_putchar((nb % 10) * -1 + '0');
}

int     my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        print_neg(nb);
    } else {
        print_pos(nb);
    }
    return (0);
}
