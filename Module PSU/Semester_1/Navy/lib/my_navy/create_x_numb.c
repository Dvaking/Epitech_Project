/*
** EPITECH PROJECT, 2023
** create x
** File description:
** create x
*/

int create_x_numb(char letter)
{
    char c = 'A';
    int x = 2;
    while (x != 16){
        if (letter != c){
            c = c + 1;
            x += 2;
        } else
            return x;
    }
    return x;
}
