/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** function that returns a number, sent to the function as a string (day 04)
*/

int my_negnbr(char const *str)
{
    int i = 0;
    int negatif = 0;

    while (str[i] == '-' || str[i] == '+'){
        if (str[i] == '-'){
            negatif += 1;
        }
        i += 1;
    }

    if ((negatif % 2) != 0){
        return (-1);
    } else {
        return (1);
    }
}

int my_getnbr(char const *str)
{
    long res = 0;
    int a = 0;
    int neg = 1;

    while (str[a] == '+' || str[a] == '-'){
        a += 1;
    }

    while (str[a] >= '0' && str[a] <= '9'){
        res = (str[a] - 48) + res * 10;
        a += 1;
        if (res > 2147483648){
            return (0);
        }
    }

    if (my_negnbr(str)*res == 2147483648){
        return (0);
    }
    return (my_negnbr(str)*res);
}
