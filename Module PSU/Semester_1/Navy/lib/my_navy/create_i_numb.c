/*
** EPITECH PROJECT, 2023
** create i
** File description:
** create i
*/

int create_i_numb(char letter)
{
    char c = '1';
    int i = 2;
    while (i != 9){
        if (letter != c){
            c = c + 1;
            i += 1;
        } else
            return i;
    }
    return i;
}
