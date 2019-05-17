/*
** EPITECH PROJECT, 2019
** my itohex
** File description:
** int to hexa
*/

#include "my.h"

char *my_itohex(int nb, char *r_hex)
{
    char *hex = "0123456789ABCDEF";
    int res = 0;

    if (nb != 0) {
        res = nb % 16;
        nb = nb / 16;
        if (nb != 0)
            r_hex = my_itohex(nb, r_hex);
    }
    r_hex = add_char(r_hex, (hex[res]));
    return (r_hex);
}

int my_hextoi(char *nb)
{
    int val = 1;
    int res = 0;
    int n_pos = my_strlen(nb) - 1;

    while (n_pos >= 0) {
        if (nb[n_pos] == '1')
            res += val;
        n_pos--;
        val *= 16;
    }
    return (res);
}

int my_bintoi(char *nb)
{
    int val = 1;
    int res = 0;
    int n_pos = strlen(nb) - 1;

    while (n_pos >= 0) {
        if (nb[n_pos] == '1')
            res += val;
        n_pos--;
      val *= 2;
    }
    return (res);
}

char *my_bintohex(char *bin)
{
    char *res = NULL;

    res = my_itohex(my_bintoi(bin), NULL);
    return (res);
}
