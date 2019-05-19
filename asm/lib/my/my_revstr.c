/*
** EPITECH PROJECT, 2019
** revstr
** File description:
** my_revstr
*/

char *my_revstr(char *str, int nb)
{
    int x = 0;
    char c;

    while (x <= nb) {
        c = str[nb];
        str[nb] = str[x];
        str[x] = c;
        x++;
        nb--;
    }
    return (str);
}
