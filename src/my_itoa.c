/*
** EPITECH PROJECT, 2018
** my_itoa
** File description:
** int to str
*/

#include "my.h"

int my_counter_of_nb(int nb)
{
    int size = nb;
    int i = 0;

    while (size > 0) {
        size /= 10;
        i++;
    }
    return (i);
}

char *my_itoa(int nb)
{
    int size = 0;
    char    *str_nb = NULL;
    int x = 0;

    if (nb == 0)
        return (my_strdup("0"));
    size = my_counter_of_nb(nb);
    str_nb = malloc(sizeof(char) * (size + 1 + x));
    str_nb[size--] = '\0';
    while (size >= 0) {
        str_nb[size] = nb % 10 + 48;
        nb /= 10;
        size--;
    }
    return (str_nb);
}
