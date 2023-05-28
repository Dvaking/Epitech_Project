/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** returns an integer indicating the result of the comparison (day 06)
*/
int     my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int a = 0;
    int count1 = 0;
    int count2 = 0;

    while (i != my_strlen(s1) && i < n){
        count1 = count1 + s1[i];
        i += 1;
    }

    while (a != my_strlen(s2) && a < n){
        count2 = count2 + s2[a];
        a += 1;
    }
    return (count1 - count2);
}
