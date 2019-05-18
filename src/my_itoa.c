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

char *neg_nb(char *str)
{
    char *nb = malloc(sizeof(char) * (my_strlen(str) + 2));
    int n = 1;
    int x = 0;

    nb[my_strlen(str) + 1] = '\0';
    nb[0] = '-';
    while (str[x] != '\0') {
        nb[n] = str[x];
        n++;
        x++;
    }
    return (nb);
}

char *my_itoa(int nb)
{
    int state = 0;
    int size = 0;
    char *str_nb = NULL;
    int x = 0;

    if (nb == 0)
        return (my_strdup("0"));
    if (nb < 0) {
        state = 1;
        nb *= -1;
    }
    size = my_counter_of_nb(nb);
    str_nb = malloc(sizeof(char) * (size + 1 + x));
    str_nb[size--] = '\0';
    while (size >= 0) {
        str_nb[size] = nb % 10 + 48;
        nb /= 10;
        size--;
    }
    if (str_nb != NULL && state == 1)
        str_nb = neg_nb(str_nb);
    return (str_nb);
}
