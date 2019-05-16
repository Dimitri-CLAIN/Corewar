/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>

char *my_compt(char *dest, char const *src)
{
    int n = 0;
    int y = 0;
    char *str;

    while (dest[n] != '\0')
        n = n + 1;
    while (src[y] != '\0')
        y = y + 1;
    y = (y + n);
    str = malloc(sizeof(char) * (y + 1));
    return (str);
}

char *my_strcat(char *dest, char const *src)
{
    int n = 0;
    int b = n;
    char *my = my_compt(dest, src);

    while (dest[b] != '\0') {
        my[n] = dest[b];
        n = n + 1;
        b = b + 1;
    }
    b = 0;
    while (src[b] != '\0') {
        my[n] = src[b];
        n = n + 1;
        b = b + 1;
    }
    my[n] = '\0';
    return (my);
}
