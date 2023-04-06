/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** prend des chiffres dans une string
*/

int positiv_or_not(char const *str)
{
    int i = 0;
    int count = 1;
    while (str[i] < '0' || str[i] > '9') {
        if (str[i] == '-') {
            count = count * -1;
        }
        i = i + 1;
    }
    if (count < 0) {
        return (1);
    }
    return (0);
}

int the_num(char const *str, int tmp, int tmp2)
{
    int value = 0;
    long int overflow = 0;
    long int i = 0;
    int percent = 1;
    int n_p = positiv_or_not(str);
    while (tmp2 >= tmp) {
        i = (str[tmp2] - 48) * percent;
        overflow = overflow + i;
        percent = percent * 10;
        tmp2 = tmp2 - 1;
    }
    if (positiv_or_not(str) == 1) {
        overflow = overflow * -1;
    }
    if (overflow > 2147483647 || overflow < -2147483648){
            return (0);
    }
    value = (int)overflow;
    return (value);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int tmp = 0;
    int tmp2 = 0;
    int num = 0;
    while (str[i] < '0' || str[i] > '9') {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'){
            return (0);
        }
        i = i + 1;
    }
    tmp = i;
    while (str[i] >= '0' && str[i] <= '9'){
        i = i + 1;
    }
    tmp2 = i - 1;
    num = the_num(str, tmp, tmp2);
    return (num);
}
